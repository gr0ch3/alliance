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
| File    :                 bddfraction.c                     |
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
# include "bddfraction.h"
# include "bddassoc.h"
# include "bddapply.h"
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
|                  Local Fraction Bdd Node                    |
|                                                             |
\------------------------------------------------------------*/

static double loc_fractionbdd( BddNode )

  bddnode  *BddNode;
{
  if ( BddNode->INDEX < BDD_INDEX_MIN )
  {
    if ( BddNode->INDEX == BDD_INDEX_ZERO )
    {
      return( 0.0 );
    }

    return( 1.0 );
  }

  return( (double)( 0.5 * ( loc_fractionbdd( BddNode->HIGH ) + 
                            loc_fractionbdd( BddNode->LOW  ) ) ) );
}

/*------------------------------------------------------------\
|                                                             |
|                    Fraction Bdd Node                        |
|                                                             |
\------------------------------------------------------------*/

double fractionbddnode( BddSystem, BddNode )

  bddsystem *BddSystem;
  bddnode   *BddNode;
{
  setbddlocalsystem( BddSystem );

  return( loc_fractionbdd( BddNode ) );
}
