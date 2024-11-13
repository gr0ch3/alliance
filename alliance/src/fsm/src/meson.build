fsm_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libabl = project_dict['libabl']

libfsm = shared_library(
    'fsm',
	'fsmadd.c',
	'fsmbdd.c',
	'fsmsearch.c',
	'fsmalloc.c',
	'fsmsimp.c',
	'fsmfree.c',
	'fsmview.c',
	'fsmorder.c',
	'fsmdel.c',
	'fsmerror.c',
	
    dependencies: [],
    link_with: [],
	include_directories: [
		fsm_includes,
		mbk_includes,
		aut_includes,
		abl_includes,
		bdd_includes
	],
    install: true,
)

ftl_includes = project_dict['ftl_includes']

libftl = project_dict['libftl']

fsm = executable(
    'fsm',
	'main.c',
	
    dependencies: [],
    link_with: [libfsm, libmbk, libaut, libabl, libftl],
	include_directories: [
		fsm_includes,
		mbk_includes,
		aut_includes,
		abl_includes,
		bdd_includes,
		ftl_includes
	],
    install: true,
)

project_dict += {'libfsm': libfsm}
