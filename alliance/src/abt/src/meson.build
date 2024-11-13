abt_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']
abe_includes = project_dict['abe_includes']

libabt = shared_library(
    'abt',
	'bhl_depend.c',
	'bhl_makbdd.c',
	'bhl_error.c',
	'bhl_delaux.c',
	'bhl_makgex.c',
	'bhl_orderbdd.c',
	'bhl_freabl.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		abt_includes,
		mbk_includes,
		aut_includes,
		abl_includes,
		bdd_includes,
		abe_includes
	],
    install: true,
)

project_dict += {'libabt': libabt}
