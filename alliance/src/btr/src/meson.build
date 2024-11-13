btr_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
log_includes = project_dict['log_includes']
bdd_includes = project_dict['bdd_includes']
beh_includes = project_dict['beh_includes']
bvl_includes = project_dict['bvl_includes']
bhl_includes = project_dict['bhl_includes']

libbtr = shared_library(
    'btr',
	'btrfree.c',
	'btrenv.c',
	'btrerror.c',
	'btrtrans.c',
	'btralloc.c',
	'btrresize.c',
	'btrfunc.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
        btr_includes,
        mbk_includes,
		aut_includes,
		abl_includes,
		log_includes,
		bdd_includes,
		beh_includes,
		bvl_includes,
		bhl_includes
    ], 
    install: true,
)

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libbdd = project_dict['libbdd']
libbeh = project_dict['libbeh']
libabl = project_dict['libabl']
libbhl = project_dict['libbhl']
libabv = project_dict['libabv']

btr = executable(
	'btr',
	'main.c',

	dependencies: [],
    link_with: [libbtr, libbdd, libbeh, libmbk, libaut, libabl, libbhl, libabv],
    include_directories: [
        btr_includes,
        mbk_includes,
		aut_includes,
		abl_includes,
		log_includes,
		bdd_includes,
		beh_includes,
		bvl_includes,
		bhl_includes
    ], 
    install: true,
)

project_dict += {'libbtr': libbtr}
