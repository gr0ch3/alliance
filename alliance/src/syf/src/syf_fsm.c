/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - D�partement ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail support : mailto:alliance-support@asim.lip6.fr       |
|                                                             |
| This progam is  free software; you can redistribute it      |
| and/or modify it under the  terms of the GNU General Public |
| License as  published by the Free Software Foundation;      |
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
| Tool    :                     SYF                           |
|                                                             |
| File    :                  syf_fsm.c                        |
|                                                             |
| Authors :                  C. Sarwary                       |
|                     Modified by Jacomme Ludovic             |
|                                                             |
| Date    :                   01.11.94                        |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include MUT_H
# include AUT_H
# include ABL_H
# include BDD_H
# include FSM_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "syf_fsm.h"

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

  char *SYF_FSM_TYPE_NAME[ SYF_FSM_MAX_TYPE ] = { "MOORE", "MEALY" };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Add Functions                       |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Syfaddfsmsyfinfo                    |
|                                                             |
\------------------------------------------------------------*/

syfinfo *Syfaddfsmsyfinfo( FsmFigure )

  fsmfig_list *FsmFigure;
{
  syfinfo *SyfInfo;

  SyfInfo = (void *)autallocblock( sizeof( syfinfo ) );
  FsmFigure->USER = (void *)SyfInfo;

  return( SyfInfo );
}

/*------------------------------------------------------------\
|                                                             |
|                         Syfaddfsmfig                        |
|                                                             |
\------------------------------------------------------------*/

fsmfig_list *Syfaddfsmfig( Name )

  char *Name;
{
  fsmfig_list *Figure;
  
  Figure = addfsmfig( Name );
  Syfaddfsmsyfinfo( Figure );

  return( Figure );
}

/*------------------------------------------------------------\
|                                                             |
|                         Syfaddfsmsyfout                     |
|                                                             |
\------------------------------------------------------------*/

syfout *Syfaddfsmsyfout( Output )

  fsmout_list *Output;
{
  syfout *SyfOut;

  SyfOut = (syfout *)autallocblock( sizeof( syfout ) );
  Output->USER = (void *)SyfOut;

  return( SyfOut );
}

/*------------------------------------------------------------\
|                                                             |
|                         Syfaddfsmsyfstate                   |
|                                                             |
\------------------------------------------------------------*/

syfstate *Syfaddfsmsyfstate( Figure, State )

  fsmfig_list   *Figure;
  fsmstate_list *State;
{
  syfstate *SyfState;
  syfinfo  *SyfInfo;
  char     *Buffer;
  int       Length;

  SyfInfo = FSM_SYF_INFO( Figure );

  SyfState    = (void *)autallocblock( sizeof( syfstate ) );
  State->USER = (void *)SyfState;

  Length = strlen( State->NAME ) + strlen( SyfInfo->CURRENT_STATE );
  Buffer = autallocblock( Length + 2 );

  sprintf( Buffer, "%s_%s", SyfInfo->CURRENT_STATE, State->NAME );
  SyfState->CURRENT_NAME = namealloc( Buffer );

  autfreeblock( Buffer );

  Length = strlen( State->NAME ) + strlen( SyfInfo->RETURN_STATE );
  Buffer = autallocblock( Length + 2 );

  sprintf( Buffer, "%s_%s", SyfInfo->RETURN_STATE, State->NAME );
  SyfState->RETURN_NAME = namealloc( Buffer );

  autfreeblock( Buffer );

  Length = strlen( State->NAME ) + strlen( SyfInfo->NEXT_STATE );
  Buffer = autallocblock( Length + 5 );

  sprintf( Buffer, "%s_%s", SyfInfo->NEXT_STATE, State->NAME );
  SyfState->NEXT_NAME = namealloc( Buffer );

  sprintf( Buffer, "%s_in_%s", SyfInfo->NEXT_STATE, State->NAME );
  SyfState->NEXT_IN_NAME = namealloc( Buffer );

  autfreeblock( Buffer );

  return( SyfState );
}
