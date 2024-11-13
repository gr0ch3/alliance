abv_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']
abe_includes = project_dict['abe_includes']

libabv = shared_library(
    'abv',
	'bvl_drive.c',
	'bvl_util.c',
	'bvl_bspec.c',
	'bvl_parse.c',
	'main.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
        abv_includes,
        mbk_includes,
        aut_includes,
        abl_includes,
        bdd_includes,
        abe_includes
    ],
    install: true,
)

project_dict += {'libabv': libabv}
