log_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']

liblog = shared_library(
    'log',
	'log_bdd0.c',
	'log_thash.c',
	'log_thashloc.c',
	'log_prefbib.c',
	'log_thashbdd.c',
	'log_bdd1.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
        log_includes,
        mbk_includes
    ], 
    install: true,
)

project_dict += {'liblog': liblog}
