loon_includes = include_directories(
    '.',
)

loon = shared_library(
    'loon',
	'lon_normalize_simplify.c',
	'lon_signal_netlist.c',
	'lon_normalize_register.c',
	'lon_xsch_driver.c',
	'lon_optim_capa.c',
	'lon_lib_format.c',
	'lon_lib_utils.c',
	'lon_lib_matching.c',
	'lon_signal_utils.c',
	'lon_normalize_message.c',
	'lon_lib_reader.c',
	'lon_lib_negativ.c',
	'lon_normalize_DAG.c',
	'lon_main.c',
	'lon_signal_critical.c',
	'lon_lib_specifications.c',
	'lon_lib_permute.c',
	'lon_signal_name.c',
	'lon_normalize_power.c',
	'lon_lax_param.c',
	'lon_optim_stats.c',
	
    dependencies: [],
    link_with: [],
    include_directories: loon_includes,
    install: true,
)
