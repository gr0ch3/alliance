/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - D�partement ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail support : mailto:alliance-support@asim.lip6.fr       |
|                                                             |
| This progam is  free software; you can redistribute it      |
| and/or modify it under the  terms of the GNU Library General|
| Public License as published by the Free Software Foundation |
| either version 2 of the License, or (at your option) any    |
| later version.                                              |
|                                                             |
| Alliance VLSI  CAD System  is distributed  in the hope that |
| it  will be useful, but WITHOUT  ANY WARRANTY;              |
| without even the  implied warranty of MERCHANTABILITY or    |
| FITNESS FOR A PARTICULAR PURPOSE. See the GNU General       |
| Public License for more details.                            |
|                                                             |
| You should have received a copy  of the GNU General Public  |
| License along with the GNU C Library; see the file COPYING. |
| If not, write to the Free Software Foundation, Inc.,        |
| 675 Mass Ave, Cambridge, MA 02139, USA.                     |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
| Tool    :                     Ctl                           |
|                                                             |
| File    :                   ctladd.c                        |
|                                                             |
| Date    :                   18.04.02                        |
|                                                             |
| Author  :               Jacomme Ludovic                     |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include "mut.h"
# include "aut.h"
# include "vex.h"
# include "ctl.h"

# include <stdio.h>
# include "ctladd.h"
# include "ctlerror.h"

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/

  ctlfig_list *HEAD_CTLFIG = (ctlfig_list *)0;

  char *CTL_DECLAR_TYPE[ CTL_MAX_DECLAR_TYPE ] =
  {
    "ALL",
    "PORT",
    "SIGNAL",
    "CONSTANT"
  };

  char *CTL_KIND_TYPE[ CTL_MAX_KIND_TYPE ] =
  {
    "NONE",
    "BUS",
    "REGISTER"
  };

  char *CTL_DIR_TYPE[ CTL_MAX_DIR_TYPE ] =
  {
    "IN",
    "OUT",
    "INOUT"
  };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      Ctl Add Functions                      |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                        Ctl Add Figure                       |
|                                                             |
\------------------------------------------------------------*/

ctlfig_list *addctlfig( Name )

   char *Name;
{
  ctlfig_list *Figure;
  int          Type;

  Figure = allocctlfig();

  Figure->NAME = namealloc( Name );
  Figure->NEXT = HEAD_CTLFIG;
  HEAD_CTLFIG  = Figure;

  for ( Type = 0; Type < CTL_MAX_DECLAR_TYPE; Type++ )
  {
    Figure->HASH_DECLAR[ Type ] = createauthtable( 50 );
  }

  return( Figure );
}

/*------------------------------------------------------------\
|                                                             |
|                       Ctl Add Declaration                   |
|                                                             |
\------------------------------------------------------------*/

static ctldecl_list *loc_addctldecl( Figure, Expr, Type, Base )

  ctlfig_list   *Figure;
  vexexpr       *Expr;
  unsigned char  Type;
  unsigned char  Base;
{
  ctldecl_list  *Decl;
  ctldecl_list **PrevDecl;
  vexexpr       *Atom;
  ctlsym        *Sym;
  char          *Name;
  int            Width;
  int            Index;
  int            IndexStep;
  int            Scan;

  if ( ! IsVexNodeAtom( Expr ) )
  {
    Atom = getvexarrayatom( Expr );
  }
  else
  {
    Atom = Expr;
  }

  Name = GetVexAtomValue( Atom );

  if ( ( Type <= CTL_DECLAR_ALL      ) ||
       ( Type >= CTL_MAX_DECLAR_TYPE ) )
  {
    ctlerror( CTL_UNKNOWN_DECLAR_TYPE, Type, Name );
  }

  Decl = allocctldecl();

  Width = Atom->WIDTH;
  Sym   = allocctlsym( Width );

  if ( ( ! IsVexNodeVarWidth( Atom ) ) &&
       ( IsVexAtomVector( Atom )     ) )
  {
    Index     = Atom->LEFT;
    IndexStep = IsVexAtomDown( Atom ) ? -1 : 1;
  }
  else
  {
    Index     = -1;
    IndexStep = 0;
  }

  for ( Scan = 0; Scan < Width; Scan++ )
  {
    Sym[ Scan ].NAME  = Name;
    Sym[ Scan ].INDEX = Index;
    Sym[ Scan ].DECL  = Decl;

    Index += IndexStep;
  }

  PrevDecl = &Figure->DECLAR[ Type ];

  Decl->VEX_ATOM  = Expr;
  Decl->DECL_SYM  = Sym;
  Decl->TYPE      = Type;
  Decl->BASE      = Base;
  Decl->PREV      = &Figure->DECLAR[ Type ];
  Decl->NEXT      = *(Decl->PREV);

  if ( Decl->NEXT != (ctldecl_list *)0 )
  {
    Decl->NEXT->PREV = &Decl->NEXT;
  }

  *(Decl->PREV) = Decl;

  addauthelem( Figure->HASH_DECLAR[ Type           ], Name, (long)Decl );
  addauthelem( Figure->HASH_DECLAR[ CTL_DECLAR_ALL ], Name, (long)Decl );

  return( Decl );
}

/*------------------------------------------------------------\
|                                                             |
|                       Ctl Add Declaration                   |
|                                                             |
\------------------------------------------------------------*/

ctldecl_list *addctldecl( Figure, Atom, Type, Base )

  ctlfig_list   *Figure;
  vexexpr       *Atom;
  unsigned char  Type;
  unsigned char  Base;
{
  ctldecl_list *Decl;
  char         *Name;

  if ( ! IsVexNodeAtom( Atom ) ) Name = getvexarrayname( Atom );
  else                           Name = GetVexAtomValue( Atom );

  Decl = searchctldeclall( Figure, Name );

  if ( Decl != (ctldecl_list *)0 )
  {
    ctlerror( CTL_DECLAR_EXIST_ERROR, Name, 0 );
  }

  Decl = loc_addctldecl( Figure, Atom, Type, Base );

  return( Decl );
}

/*------------------------------------------------------------\
|                                                             |
|                      Ctl Add Declaration Port               |
|                                                             |
\------------------------------------------------------------*/

ctldecl_list *addctldeclport( Figure, Atom, Base, Dir, Kind )

   ctlfig_list   *Figure;
   vexexpr       *Atom;
   unsigned char  Base;
   unsigned char  Dir;
   unsigned char  Kind;
{
  ctldecl_list *Port;
  char         *Name;

  if ( ! IsVexNodeAtom( Atom ) ) Name = getvexarrayname( Atom );
  else                           Name = GetVexAtomValue( Atom );

  Port = searchctldeclall( Figure, Name );

  if ( Port != (ctldecl_list *)0 )
  {
    ctlerror( CTL_PORT_EXIST_ERROR, Name, 0 );
  }

  Port = loc_addctldecl( Figure, Atom, CTL_DECLAR_PORT, Base );
  Port->DIR  = Dir;
  Port->KIND = Kind;

  return( Port );
}

/*------------------------------------------------------------\
|                                                             |
|                     Ctl Add Declaration Signal              |
|                                                             |
\------------------------------------------------------------*/

ctldecl_list *addctldeclsig( Figure, Atom, Base, Kind )

   ctlfig_list   *Figure;
   vexexpr       *Atom;
   unsigned char  Base;
   unsigned char  Kind;
{
  ctldecl_list *Signal;
  char         *Name;

  if ( ! IsVexNodeAtom( Atom ) ) Name = getvexarrayname( Atom );
  else                           Name = GetVexAtomValue( Atom );

  Signal = searchctldeclall( Figure, Name );

  if ( Signal != (ctldecl_list *)0 )
  {
    ctlerror( CTL_SIGNAL_EXIST_ERROR, Name, 0 );
  }

  Signal = loc_addctldecl( Figure, Atom, CTL_DECLAR_SIGNAL, Base );
  Signal->DIR  = CTL_DIR_INOUT;
  Signal->KIND = Kind;

  return( Signal );
}

/*------------------------------------------------------------\
|                                                             |
|                     Ctl Add Declaration Constant            |
|                                                             |
\------------------------------------------------------------*/

ctldecl_list *addctldeclcst( Figure, Atom, Base )

   ctlfig_list   *Figure;
   vexexpr       *Atom;
   unsigned char  Base;
{
  ctldecl_list *Constant;
  char         *Name;

  if ( ! IsVexNodeAtom( Atom ) ) Name = getvexarrayname( Atom );
  else                           Name = GetVexAtomValue( Atom );

  Constant = searchctldeclall( Figure, Name );

  if ( Constant != (ctldecl_list *)0 )
  {
    ctlerror( CTL_CONSTANT_EXIST_ERROR, Name, 0 );
  }

  Constant = loc_addctldecl( Figure, Atom, CTL_DECLAR_CONSTANT, Base );
  Constant->DIR  = CTL_DIR_IN;

  return( Constant );
}

/*------------------------------------------------------------\
|                                                             |
|                         Ctl Add File Line                   |
|                                                             |
\------------------------------------------------------------*/

ctlline_list *addctlfileline( Figure, HeadLine, File, Line )

  ctlfig_list   *Figure;
  ctlline_list **HeadLine;
  char          *File;
  long           Line;
{
  ctlline_list **PrevLine;
  ctlline_list  *CtlLine;

  File = autnamealloc( File );

  PrevLine = HeadLine;

  for ( CtlLine  = *PrevLine;
        CtlLine != (ctlline_list *)0;
        CtlLine  = CtlLine->NEXT )
  {
    if ( CtlLine->NAME == File )
    {
      if ( CtlLine->LINE == Line ) return( CtlLine );
      if ( CtlLine->LINE <  Line ) PrevLine = &CtlLine->NEXT;
    }
  }

  CtlLine = allocctlline();

  CtlLine->LINE = Line;
  CtlLine->NAME = File;
  CtlLine->NEXT = *PrevLine;
  *PrevLine     = CtlLine;

  return( CtlLine );
}

/*------------------------------------------------------------\
|                                                             |
|                         Ctl Add Line                        |
|                                                             |
\------------------------------------------------------------*/

ctlline_list *addctlline( Figure, HeadLine, Line )

  ctlfig_list   *Figure;
  ctlline_list **HeadLine;
  long           Line;
{
  return( addctlfileline( Figure, HeadLine, (char *)0, Line ) );
}

/*------------------------------------------------------------\
|                                                             |
|                        Ctl Add Form                         |
|                                                             |
\------------------------------------------------------------*/

ctlform_list *addctlform( Figure, Name, Expr )

  ctlfig_list   *Figure;
  char          *Name;
  vexexpr       *Expr;
{
  ctlform_list *Form;

  Form = allocctlform();

  Form->NAME     = namealloc( Name );;
  Form->VEX_EXPR = Expr;

  Form->NEXT   = Figure->FORM;
  Figure->FORM = Form;

  return( Form );
}
