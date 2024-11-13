bhl_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
log_includes = project_dict['log_includes']
beh_includes = project_dict['beh_includes']

libbhl = shared_library(
    'bhl',
	'beh_freabl.c',
	'beh_sta2dly.c',
	'beh_dly2sta.c',
	'beh_maknode.c',
	'beh_makderiv.c',
	'beh_unamlist.c',
	'beh_makquad.c',
	'beh_makbdd.c',
	'beh_gettu.c',
	'beh_clrdepend.c',
	'beh_makgex.c',
	'beh_makvarlist.c',
	'beh_chkbefig.c',
	'beh_depend.c',
	'beh_namelist.c',
	'beh_debug.c',
	'beh_indexbdd.c',
	
    dependencies: [],
    link_with: [],
	include_directories: [
      bhl_includes,
      mbk_includes,
	  log_includes,
	  beh_includes
    ],
    install: true,
)

project_dict += {'libbhl': libbhl}
