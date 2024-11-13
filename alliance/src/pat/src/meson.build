pat_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']

libpat = shared_library(
    'pat',
	'pat_drvpat.c',
	'pat_frepaini.c',
	'pat_globals.c',
	'pat_frepaevt.c',
	'pat_addpains.c',
	'pat_lodpaseq.c',
	'pat_addpaseq.c',
	'pat_message.c',
	'pat_error.c',
	'pat_pattostr.c',
	'pat_getusage.c',
	'pat_debug.c',
	'pat_frepapat.c',
	'pat_addpaiol.c',
	'pat_addpacom.c',
	'pat_addpaevt.c',
	'pat_addpaini.c',
	'pat_addpagrp.c',
	'pat_prspat.c',
	'pat_frepaiol.c',
	'pat_savpaseq.c',
	'pat_warning.c',
	'pat_frepacom.c',
	'pat_crtpaiol.c',
	'pat_addpapat.c',
	
    dependencies: [],
    link_with: [],
	include_directories: [
      pat_includes,
      mbk_includes,
    ],
    install: true,
)

project_dict += {'libpat': libpat}
