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
| File    :                  syf_simp.c                       |
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
# include FVH_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "syf_fsm.h"
# include "syf_tools.h"
# include "syf_bdd.h"
# include "syf_simp.h"
# include "syf_error.h"

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
/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                        SyfFbhSimplify                       |
|                                                             |
\------------------------------------------------------------*/


void SyfFbhSimplify( FbhFigure )

  fbfig_list *FbhFigure;
{
  fbout_list *FbOut;
  fbreg_list *FbReg;
  biabl_list *FbBiabl;
  fbaux_list *FbAux;

  for ( FbAux  = FbhFigure->BEAUX;
        FbAux != (fbaux_list *)0;
        FbAux  = FbAux->NEXT )
  {
    if ( FbAux->ABL != (chain_list *)0 )
    {
      FbAux->ABL = simpablexpr( FbAux->ABL );
    }
  }

  for ( FbOut  = FbhFigure->BEOUT;
        FbOut != (fbout_list *)0;
        FbOut  = FbOut->NEXT )
  {
    if ( FbOut->ABL != (chain_list *)0 )
    {
      FbOut->ABL = simpablexpr( FbOut->ABL );
    }
  }

  for ( FbReg  = FbhFigure->BEREG;
        FbReg != (fbreg_list *)0;
        FbReg  = FbReg->NEXT )
  {
    for ( FbBiabl  = FbReg->BIABL;
          FbBiabl != (biabl_list *)0;
          FbBiabl  = FbBiabl->NEXT )
    {
      if ( ( FbBiabl->CNDABL != (chain_list *)0 ) &&
           ( FbBiabl->VALABL != (chain_list *)0 ) )
      {
        FbBiabl->CNDABL = simpablexpr( FbBiabl->CNDABL );
        FbBiabl->VALABL = simpablexpr( FbBiabl->VALABL );
      }
    }
  }
}
