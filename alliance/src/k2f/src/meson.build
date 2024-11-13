k2f_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']
fsm_includes = project_dict['fsm_includes']
ftl_includes = project_dict['ftl_includes']

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libbdd = project_dict['libbdd']
libabl = project_dict['libabl']
libftl = project_dict['libftl']

k2f = executable(
    'k2f',
	'k2f_error.c',
	'k2f_main.c',
	
    dependencies: [],
    link_with: [libmbk, libaut, libbdd, libabl, libftl],
    include_directories: [
		k2f_includes,
		mbk_includes,
		aut_includes,
        abl_includes,
        bdd_includes,
        fsm_includes,
        ftl_includes
	],
    install: true,
)
