b2f_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']
btr_includes = project_dict['btr_includes']
fsm_includes = project_dict['fsm_includes']
abe_includes = project_dict['abe_includes']
abv_includes = project_dict['abv_includes']
abt_includes = project_dict['abt_includes']
ftl_includes = project_dict['ftl_includes']

libb2f = shared_library(
    'b2f',
	'b2f_beh2fsm.c',
	'b2f_error.c',
	'b2f_main.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
        b2f_includes,
        mbk_includes,
        aut_includes,
        abl_includes,
        bdd_includes,
        btr_includes,
        fsm_includes,
        abe_includes,
        abv_includes,
        abt_includes,
        ftl_includes
    ], 
    install: true,
)

project_dict += {'libb2f': libb2f}
