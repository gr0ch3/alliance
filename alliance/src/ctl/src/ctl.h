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
#ifndef __P
# if defined(__STDC__) ||  defined(__GNUC__)
#  define __P(x) x
# else
#  define __P(x) ()
# endif
#endif
/*------------------------------------------------------\
|                                                       |
|  Title   :   Structures and fonctions for CTL         |
|                                                       |
|  Date    :            04.18.2002                      |
|                                                       |
|  Author  :        Jacomme Ludovic                     |
|                                                       |
\------------------------------------------------------*/

# ifndef CTL_H
# define CTL_H

/*------------------------------------------------------\
|                                                       |
|                      Constants                        |
|                                                       |
\------------------------------------------------------*/
/*------------------------------------------------------\
|                                                       |
|                       Ctl Declar Type                 |
|                                                       |
\------------------------------------------------------*/

# define CTL_DECLAR_ALL             0
# define CTL_DECLAR_VARIABLE        1
# define CTL_DECLAR_CONSTANT        2
# define CTL_MAX_DECLAR_TYPE        3

/*------------------------------------------------------\
|                                                       |
|                        Macros                         |
|                                                       |
\------------------------------------------------------*/
/*------------------------------------------------------\
|                                                       |
|                      Ctl Get Symbol                   |
|                                                       |
\------------------------------------------------------*/

# define GetCtlSymbol( C ) ((ctlsym       *)( (C)->DATA ))
# define GetCtlDeclar( C ) ((ctldecl_list *)( (C)->DATA ))

/*------------------------------------------------------\
|                                                       |
|                        Ctl Get Number                 |
|                                                       |
\------------------------------------------------------*/

# define GetCtlNumDecl( F )     ((F)->HASH_DECLAR[ CTL_DECLAR_ALL      ]->NUMBER_ELEM)
# define GetCtlNumDeclVar( F )  ((F)->HASH_DECLAR[ CTL_DECLAR_VARIABLE ]->NUMBER_ELEM)
# define GetCtlNumDeclCst( F )  ((F)->HASH_DECLAR[ CTL_DECLAR_CONSTANT ]->NUMBER_ELEM)

/*------------------------------------------------------\
|                                                       |
|                    Ctl Search Symbol                  |
|                                                       |
\------------------------------------------------------*/

# define searchctlsymvar( F, N, I ) \
    (searchctlsym( (F), (N), (I), CTL_DECLAR_VARIABLE ))
# define searchctlsymcst( F, N, I ) \
    (searchctlsym( (F), (N), (I), CTL_DECLAR_CONSTANT ))
# define searchctlsymall( F, N, I ) \
    (searchctlsym( (F), (N), (I), CTL_DECLAR_ALL ))

/*------------------------------------------------------\
|                                                       |
|                    Ctl Search Declar                  |
|                                                       |
\------------------------------------------------------*/

# define searchctldeclvar( F, N ) \
    (searchctldecl( (F), (N), CTL_DECLAR_VARIABLE ))
# define searchctldeclcst( F, N ) \
    (searchctldecl( (F), (N), CTL_DECLAR_CONSTANT ))
# define searchctldeclall( F, N ) \
    (searchctldecl( (F), (N), CTL_DECLAR_ALL ))

/*------------------------------------------------------\
|                                                       |
|                         Type                          |
|                                                       |
\------------------------------------------------------*/
/*------------------------------------------------------\
|                                                       |
|                        Ctl Line                       |
|                                                       |
\------------------------------------------------------*/

  typedef struct ctlline_list
  {
    struct ctlline_list *NEXT;
    char                *NAME;
    long                 LINE;

  } ctlline_list;

/*------------------------------------------------------\
|                                                       |
|                       Ctl Type                        |
|                                                       |
\------------------------------------------------------*/

typedef struct ctltype_list
{
  struct ctltype_list *NEXT;
  char                *NAME;
  unsigned long        SIZE;
  char               **VALUE;
  ctlline_list        *LINE;
  long                 FLAGS;
  void                *USER;

} ctltype_list;

/*------------------------------------------------------\
|                                                       |
|                        Ctl Symbol                     |
|                                                       |
\------------------------------------------------------*/

  typedef struct ctlsym
  {
    char                  *NAME;
    struct ctldecl_list   *DECL;
    short                  INDEX;
    long                   FLAGS;
    void                  *USER;

  } ctlsym;

/*------------------------------------------------------\
|                                                       |
|                     Ctl Declaration                   |
|                                                       |
\------------------------------------------------------*/

  typedef struct ctldecl_list
  {
    struct ctldecl_list  *NEXT;
    struct ctldecl_list **PREV;
    vexexpr              *VEX_ATOM;
    vexexpr              *VEX_INIT;
    ctlsym               *DECL_SYM;
    ctltype_list         *USER_TYPE;
    unsigned char         TYPE;
    ctlline_list         *LINE;
    long                  FLAGS;
    void                 *USER;

  } ctldecl_list;

/*------------------------------------------------------\
|                                                       |
|                    Ctl Formula                        |
|                                                       |
\------------------------------------------------------*/

  typedef struct ctlform_list
  {
    struct ctlform_list   *NEXT;
    struct ctlform_list  **PREV;
    char                  *NAME;
    vexexpr               *VEX_EXPR;
    ctlline_list          *LINE;
    long                   FLAGS;
    void                  *USER;

  } ctlform_list;

/*------------------------------------------------------\
|                                                       |
|                        Ctl Figure                     |
|                                                       |
\------------------------------------------------------*/

  typedef struct ctlfig_list
  {
    struct ctlfig_list *NEXT;
    char               *NAME;
    ctltype_list       *TYPE;
    ctlform_list       *FORM;
    ctldecl_list       *DECLAR[ CTL_MAX_DECLAR_TYPE ];
    authtable          *HASH_DECLAR[ CTL_MAX_DECLAR_TYPE ];
    void               *CIRCUIT;
    long                FLAGS;
    void               *USER;

  } ctlfig_list;

/*------------------------------------------------------\
|                                                       |
|                     Global Variables                  |
|                                                       |
\------------------------------------------------------*/

  extern ctlfig_list *HEAD_CTLFIG;

  extern char  *CTL_DECLAR_TYPE   [ CTL_MAX_DECLAR_TYPE ];

/*------------------------------------------------------\
|                                                       |
|                        Functions                      |
|                                                       |
\------------------------------------------------------*/
/*------------------------------------------------------\
|                                                       |
|                       Env Functions                   |
|                                                       |
\------------------------------------------------------*/

  extern void ctlenv __P(());

/*------------------------------------------------------\
|                                                       |
|                    Alloc Functions                    |
|                                                       |
\------------------------------------------------------*/

  extern   ctlfig_list *allocctlfig __P(());
  extern  ctlform_list *allocctlform __P(());
  extern  ctltype_list *allocctltype __P(());
  extern  ctldecl_list *allocctldecl __P(());
  extern        ctlsym *allocctlsym __P((unsigned int Width));
  extern  ctlline_list *allocctlline __P(());

/*------------------------------------------------------\
|                                                       |
|                      Free Functions                   |
|                                                       |
\------------------------------------------------------*/

  extern void  freectlfig __P((ctlfig_list *Figure));
  extern void  freectlform __P((ctlform_list *Form));
  extern void  freectldecl __P((ctldecl_list *Decl));
  extern void  freectlsym __P((ctlsym *Sym));
  extern void  freectlline __P((ctlline_list *Line));

/*------------------------------------------------------\
|                                                       |
|                      Add Functions                    |
|                                                       |
\------------------------------------------------------*/

  extern  ctlfig_list *addctlfig __P((char *Name));
  extern ctlform_list *addctlform __P((ctlfig_list *Figure, char *Name, vexexpr *Expr));
  extern ctltype_list *addctltype __P((ctlfig_list *Figure, char *Name));

  extern ctldecl_list *addctldecl __P((ctlfig_list *Figure, vexexpr *Atom, unsigned char Type ));
  extern ctldecl_list *addctldeclvar __P((ctlfig_list *Figure, vexexpr *Atom));
  extern ctldecl_list *addctldeclcst __P((ctlfig_list *Figure, vexexpr *Atom));

  extern  ctlline_list *addctlline __P((ctlfig_list *Figure, ctlline_list **HeadLine, long Line));
  extern  ctlline_list *addctlfileline __P((ctlfig_list *Figure, ctlline_list **HeadLine, char *File, long Line));

/*------------------------------------------------------\
|                                                       |
|                       Get Functions                   |
|                                                       |
\------------------------------------------------------*/

  extern        ctlsym *getctlsymdecl __P((ctldecl_list *Declar, short Index));
  extern        ctlsym *getctlsymdeclpos __P((ctldecl_list *Declar, int Position));

/*------------------------------------------------------\
|                                                       |
|                    Search Functions                   |
|                                                       |
\------------------------------------------------------*/

  extern   ctlfig_list *searchctlfig __P((char *Name));
  extern  ctlform_list *searchctlform __P((ctlfig_list *Figure, char *Name));
  extern  ctltype_list *searchctltype __P((ctlfig_list *Figure, char *Name));
  extern        ctlsym *searchctlsym __P((ctlfig_list *Figure, char *Name, short Index, unsigned char Type));
  extern  ctldecl_list *searchctldecl __P((ctlfig_list *Figure, char *Name, unsigned char Type));

/*------------------------------------------------------\
|                                                       |
|                    Delete Functions                   |
|                                                       |
\------------------------------------------------------*/

  extern int  delctlfig __P((char *Name));
  extern int  delctlline __P((ctlfig_list *Figure, ctlline_list **PrevLine, ctlline_list *Line));
  extern int  delctlform __P((ctlfig_list *Figure, ctlform_list *Form));

/*------------------------------------------------------\
|                                                       |
|                     View Functions                    |
|                                                       |
\------------------------------------------------------*/

  extern void  viewctlfig __P((ctlfig_list *Figure));
  extern void  viewctlsym __P((ctlsym *Symbol));
  extern void  viewctldecl __P((ctldecl_list *Decl));
  extern void  viewctlform __P((ctlform_list *Form));
  extern void  viewctltype __P((ctltype_list *Type));
  extern void  viewctlline __P((ctlline_list *Line));

# endif