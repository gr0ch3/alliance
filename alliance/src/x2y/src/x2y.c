/*
 * This file is part of the Alliance CAD System
 * Copyright (C) Laboratoire LIP6 - D�partement ASIM
 * Universite Pierre et Marie Curie
 * 
 * Home page          : http://www-asim.lip6.fr/alliance/
 * E-mail support     : mailto:alliance-support@asim.lip6.fr
 * 
 * This progam is  free software; you can redistribute it  and/or modify it
 * under the  terms of the GNU  General Public License as  published by the
 * Free Software Foundation;  either version 2 of the License,  or (at your
 * option) any later version.
 * 
 * Alliance VLSI  CAD System  is distributed  in the hope  that it  will be
 * useful, but WITHOUT  ANY WARRANTY; without even the  implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy  of the GNU General Public License along
 * with the GNU C Library; see the  file COPYING. If not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ident "$Id: x2y.c,v 1.1 2002/04/29 14:15:52 czo Exp $"
#include <stdio.h>
#include <string.h>
#include "mut.h"
#include "mlo.h"
#include "mph.h"

/***********************************************************************
	CP		layout VTI
	HNS	 	netlist VTI
	FNE	 	extracted netlist VTI
??	FDN	 	extracted netlist DAX
??	HDN	 	extracted hierarchical netlist DAX

	AP	 	layout ALLIANCE
	AL	 	netlist ALLIANCE

	EDI	 	netlist or layout EDIF

	CCT	 	structurel HILO
	VST	 	structurel VHDL 

	SPI	 	structurel SPICE 
***********************************************************************/


int main( argc, argv )

  int argc;
  char **argv;
{
  lofig_list *LogicalFigure;
  phfig_list *PhysicalFigure;
  char       *InputName;
  char       *OutputName;
  char       *InputFormat;
  char       *OutputFormat;
  int         MbkIn;
  int         MbkOut;

  mbkenv();

  alliancebanner ("x2y", "1.4", "MBK Format Translator", "1990", ALLIANCE_VERSION);

  if ( argc != 5 )
  {
    fprintf( stdout, "\tSyntax: x2y in_format out_format in_file out_file\n" );
    return( 1 );
  }

  InputFormat  = namealloc( argv[ 1 ] );
  OutputFormat = namealloc( argv[ 2 ] );
  InputName    = namealloc( argv[ 3 ] );
  OutputName   = namealloc( argv[ 4 ] );

  if ( ( !strcmp( InputFormat, "al"  ) ) ||
       ( !strcmp( InputFormat, "vst" ) ) ||
       ( !strcmp( InputFormat, "cct" ) ) ||
       ( !strcmp( InputFormat, "edi" ) ) ||
       ( !strcmp( InputFormat, "vlg" ) ) ||
       ( !strcmp( InputFormat, "spi" ) ) ||
       ( !strcmp( InputFormat, "sp"  ) ) ||
       ( !strcmp( InputFormat, "cir" ) ) ||
       ( !strcmp( InputFormat, "fne" ) ) ||
       ( !strcmp( InputFormat, "hns" ) ) )
  {
    MbkIn = 1; strcpy( IN_LO, InputFormat );
  }
  else
  if ( ( !strcmp( InputFormat, "ap" ) ) ||
       ( !strcmp( InputFormat, "cp" ) ) )
  {
    MbkIn = 2; strcpy( IN_PH, InputFormat );
  }
  else
  {
    fprintf( stderr, "Bad mbk input file format %s\n", InputFormat );
    return( 1 );
  }

  if ( ( !strcmp( OutputFormat, "al"  ) ) ||
       ( !strcmp( OutputFormat, "vst" ) ) ||
       ( !strcmp( OutputFormat, "cct" ) ) ||
       ( !strcmp( OutputFormat, "edi" ) ) ||
       ( !strcmp( OutputFormat, "vlg" ) ) ||
       ( !strcmp( OutputFormat, "spi" ) ) ||
       ( !strcmp( OutputFormat, "sp"  ) ) ||
       ( !strcmp( OutputFormat, "cir" ) ) ||
       ( !strcmp( OutputFormat, "fne" ) ) ||
       ( !strcmp( OutputFormat, "hns" ) ) )
  {
    MbkOut = 1; strcpy( OUT_LO, OutputFormat );
  }
  else
  if ( ( !strcmp( OutputFormat, "ap" ) ) ||
       ( !strcmp( OutputFormat, "cp" ) ) )
  {
    MbkOut = 2; strcpy( OUT_PH, OutputFormat );
  }
  else
  {
    fprintf( stderr, "Bad mbk output file format %s\n", InputFormat );
    return( 1 );
  }

  if ( MbkOut != MbkIn )
  {
    fprintf( stderr, "Incompatible mbk input/output file format !\n" );
    return( 1 );
  }

  fprintf( stdout, "\t--> Conversion of %s(%s) to %s(%s)\n", 
           InputName, InputFormat, OutputName, OutputFormat );

  if ( MbkIn  == 1 ) LogicalFigure  = getlofig( InputName, 'A' );
  else               PhysicalFigure = getphfig( InputName, 'A' );

  if ( MbkOut == 1 ) 
  {
    LogicalFigure -> NAME = OutputName;
    savelofig( LogicalFigure  );
  }
  else
  { 
    PhysicalFigure -> NAME = OutputName;
    savephfig( PhysicalFigure );
  } 
  fprintf( stdout, "\t--> File format translation's done !\n" );

  return( 0 );
}