boom_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']
abe_includes = project_dict['abe_includes']
abv_includes = project_dict['abv_includes']
abt_includes = project_dict['abt_includes']

libboom = shared_library(
    'boom',
	'boom_abl.c',
	'boom_order.c',
	'boom_param.c',
	'boom_optim.c',
	'boom_one.c',
	# 'boom_logic.c',  # Build error: symbols are missing project-wide
	'boom_check.c',
	'boom_simul.c',
	'boom_bdd.c',
	'boom_hash.c',
	'boom_random.c',
	'boom_debug.c',
	'boom_anneal.c',
	'boom_auxinit.c',
	'boom_error.c',
	'boom_post.c',
	'boom_burgun.c',
	'boom_top.c',
	'boom_shared.c',
	'boom_gradient.c',
	'boom_simple.c',
	'boom_procrast.c',
	'boom_cost.c',
	'boom_parse.c',
	'boom_aux.c',
	'boom_window.c',
	'boom_drive.c',
	'boom_dc.c',
	
    dependencies: [],
    link_with: [],
	include_directories: [
        boom_includes,
        mbk_includes,
		aut_includes,
		abl_includes,
		bdd_includes,
		abe_includes,
		abv_includes,
		abt_includes
	],
    install: true,
)

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libbdd = project_dict['libbdd']
libabl = project_dict['libabl']

boom = executable(
    'boom',
	'boom_main.c',
	
    dependencies: [],
    link_with: [libboom, libmbk, libaut, libbdd, libabl],
	include_directories: [
        boom_includes,
        mbk_includes,
		aut_includes,
		abl_includes,
		bdd_includes,
		abe_includes,
		abv_includes,
		abt_includes
    ], 
    install: true,
)

project_dict += {'libboom': libboom}
