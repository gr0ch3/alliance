/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - Département ASIM Universite P&M Curie|
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
| Tool    :                   XSCH                           |
|                                                             |
| File    :                   View.h                          |
|                                                             |
| Authors :              Jacomme Ludovic                      |
|                                                             |
| Date    :                   01.06.96                        |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# ifndef XSCH_VIEW
# define XSCH_VIEW

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# define XSCH_PERCENT_ZOOM      30
# define XSCH_PERCENT_ZOOM_MIN   5
# define XSCH_PERCENT_ZOOM_MAX  95

# define XSCH_PERCENT_MOVE      30
# define XSCH_PERCENT_MOVE_MIN   5
# define XSCH_PERCENT_MOVE_MAX  95

/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/

  typedef struct xschzoom
   {
     struct xschzoom *NEXT;

     long              X;
     long              Y;
     long             DX;
     long             DY;

   } xschzoom;

/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/

  extern int            XschPercentZoom;
  extern int            XschPercentMove;

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/

  extern void XschZoomUndo();
  extern void XschZoomRefresh();

  extern void XschZoomLeft();
  extern void XschZoomRight();
  extern void XschZoomUp();
  extern void XschZoomDown();

  extern void XschZoomMore();
  extern void XschZoomLess();

  extern void XschZoomFit();

  extern void XschInitializeZoom();
  extern void XschInitializeUnitGrid();

# endif 
