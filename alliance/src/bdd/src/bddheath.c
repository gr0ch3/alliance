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
| Tool    :                     Bdd                           |
|                                                             |
| File    :                   bddheath.c                      |
|                                                             |
| Date    :                   03.12.96                        |
|                                                             |
| Author  :               Jacomme Ludovic                     |
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

# include <stdio.h>
# include "bddheath.h"
# include "bdderror.h"

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
|                           Variable                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                       Get Bdd Var Heath                     |
|                                                             |
\------------------------------------------------------------*/

bddheath *getbddheathvar( BddSystem, BddNode, Variable )

  bddsystem *BddSystem;
  bddnode   *BddNode;
  bddvar     Variable;
{
  bddheath   *BddHeath;
  bddnode    *BddVarNode;
  bddindex    Index;

  checkbddvar( BddSystem, Variable, 1 );
  
  Index      = BddLocalSystem->VAR_TO_INDEX[ Variable ];
  BddVarNode = BddLocalSystem->VAR_NODE[ Index ];

  BddHeath = allocbddheath();
  BddHeath->VAR = BddVarNode;

  BddHeath->PLUS  = restrictbddnode( (bddsystem *)0, BddNode, Variable, BddLocalSystem->ONE  );
  BddHeath->MINUS = restrictbddnode( (bddsystem *)0, BddNode, Variable, BddLocalSystem->ZERO );

  return( BddHeath );
}

/*------------------------------------------------------------\
|                                                             |
|                        Get Bdd Heath                        |
|                                                             |
\------------------------------------------------------------*/

bddheath *getbddheath( BddSystem, BddNode )

  bddsystem *BddSystem;
  bddnode   *BddNode;
{
  chain_list *Support;
  chain_list *ScanSupport;
  bddheath   *HeadHeath;
  bddheath   *BddHeath;
  bddvar      BddVar;

  setbddlocalsystem( BddSystem );

  Support   = getbddnodesupport( (bddsystem *)0, BddNode, BDD_SUPPORT_CHAIN );
  HeadHeath = (bddheath *)0;

  for ( ScanSupport  = Support;
        ScanSupport != (chain_list *)0;
        ScanSupport  = ScanSupport->NEXT )
  {
    BddHeath = allocbddheath();
    BddHeath->NEXT = HeadHeath;
    BddHeath->VAR  = (bddnode *)( ScanSupport->DATA );

    BddVar          = BddLocalSystem->INDEX_TO_VAR[ BddHeath->VAR->INDEX ];
    BddHeath->PLUS  = restrictbddnode( (bddsystem *)0, BddNode, BddVar, BddLocalSystem->ONE  );
    BddHeath->MINUS = restrictbddnode( (bddsystem *)0, BddNode, BddVar, BddLocalSystem->ZERO );

    HeadHeath = BddHeath;
  }

  freechain( Support );

  return( HeadHeath );
}

/*------------------------------------------------------------\
|                                                             |
|                      Del Bdd Heath                          |
|                                                             |
\------------------------------------------------------------*/

void delbddheath( BddSystem, BddHeath )

  bddsystem *BddSystem;
  bddheath  *BddHeath;
{
  bddheath *DelHeath;

  setbddlocalsystem( BddSystem );

  while ( BddHeath != (bddheath *)0 )
  {
    DelHeath = BddHeath;
    BddHeath = BddHeath->NEXT;

    decbddrefext( DelHeath->PLUS  );
    decbddrefext( DelHeath->MINUS );

    freebddheath( DelHeath );
  }
}
