boog_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
bdd_includes = project_dict['bdd_includes']
abl_includes = project_dict['abl_includes']
abe_includes = project_dict['abe_includes']
abv_includes = project_dict['abv_includes']

libboog = shared_library(
    'boog',
	'bog_lib_matching.c',
	'bog_map_prepare.c',
	'bog_lib_specifications.c',
	'bog_lib_reader.c',
	'bog_signal_nameindex.c',
	'bog_lib_complete.c',
	'bog_xsch_driver.c',
	'bog_lib_utils.c',
	'bog_signal_utils.c',
	'bog_map_befig.c',
	'bog_normalize_message.c',
	'bog_normalize_power.c',
	'bog_unflatten_abl.c',
	'bog_lib_cell.c',
	'bog_map_pattern.c',
	'bog_normalize_DAG.c',
	'bog_unflatten_delay.c',
	'bog_normalize_DC.c',
	'bog_main.c',
	'bog_map_delay.c',
	'bog_signal_adapt.c',
	'bog_unflatten_befig.c',
	'bog_normalize_ARITY.c',
	'bog_lax_param.c',
	'bog_unflatten_utils.c',
	'bog_lib_negativ.c',
	'bog_unflatten_area.c',
	'bog_normalize_simplify.c',
	'bog_map_abl.c',
	'bog_map_adapt.c',
	'bog_normalize_register.c',
	'bog_lib_format.c',
	'bog_unflatten_oper.c',
	'bog_lib_permute.c',
	'bog_signal_delay.c',
	'bog_normalize_nameindex.c',
	
    dependencies: [],
    link_with: [],
	include_directories: [
        boog_includes,
        mbk_includes,
		aut_includes,
		bdd_includes,
		abl_includes,
		abe_includes,
		abv_includes
    ], 
    install: true,
)

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libbdd = project_dict['libbdd']
libabl = project_dict['libabl']
libabv = project_dict['libabv']

boog = executable(
    'boog',
	'bog_main.c',
	
    dependencies: [],
    link_with: [libboog, libmbk, libaut, libabl, libbdd, libabv],
	include_directories: [
        boog_includes,
        mbk_includes,
		aut_includes,
		bdd_includes,
		abl_includes,
		abe_includes,
		abv_includes
    ], 
    install: true,
)

project_dict += {'libboog': libboog}
