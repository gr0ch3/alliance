ftl_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']
fsm_includes = project_dict['fsm_includes']

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libabl = project_dict['libabl']

# WARNING: File main.c is an exact copy of ../fsm/src/main.cpp that causes cyclic dependency

libftl = shared_library(
    'ftl',
	'ftlerror.c',
	'ftlacces.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		ftl_includes,
		mbk_includes,
		aut_includes,
        abl_includes,
        bdd_includes,
        fsm_includes
	],
    install: true,
)

project_dict += {'libftl': libftl}
