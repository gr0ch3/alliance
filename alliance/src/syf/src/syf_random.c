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
| File    :                   random.c                        |
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
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# include MUT_H
# include AUT_H
# include ABL_H
# include BDD_H
# include FSM_H

# include "syf_fsm.h"
# include "syf_error.h"
# include "syf_random.h"

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

  static char SyfInitializedRandom = 0;

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                        SyfInitializeRandom                  |
|                                                             |
\------------------------------------------------------------*/

void SyfInitializeRandom()
{
  if ( ! SyfInitializedRandom )
  {
    SyfInitializedRandom = 1;

    srand( getpid() );
  }
}

/*------------------------------------------------------------\
|                                                             |
|                        SyfRandomEncode                      |
|                                                             |
\------------------------------------------------------------*/

void SyfFsmRandomEncode( FsmFigure )

  fsmfig_list *FsmFigure;
{
  syfinfo       *SyfInfo;
  fsmstate_list *ScanState;
  syfcode       *CodeArray;
  long           CodeMax;
  int            Index;
  int            Swap;
  int            Scan;

  SyfInitializeRandom();

  SyfInfo   = FSM_SYF_INFO( FsmFigure );
  CodeMax   = SyfInfo->NUMBER_CODE;
  CodeArray = SyfInfo->CODE_ARRAY;

  for ( Index = 0; Index < CodeMax; Index++ )
  {
    CodeArray[ Index ].VALUE = Index;
  }

  ScanState = FsmFigure->STATE;

  while ( ScanState != (fsmstate_list *)0 )
  {
    Scan = ( rand() >> 8 ) % CodeMax;

    CodeMax = CodeMax - 1;

    FSM_SYF_STATE( ScanState )->CODE = &CodeArray[ CodeMax ];

    CodeArray[ CodeMax ].USED  = 1;

    if ( Scan != CodeMax )
    {
      Swap                       = CodeArray[ CodeMax ].VALUE;
      CodeArray[ CodeMax ].VALUE = CodeArray[ Scan    ].VALUE;
      CodeArray[ Scan    ].VALUE = Swap;
    }

    ScanState = ScanState->NEXT;
  }
}
