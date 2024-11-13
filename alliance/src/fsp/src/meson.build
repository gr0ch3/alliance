fsp_includes = include_directories(
    '.',
)

fsp = shared_library(
    'fsp',
	'fsp_debug.c',
	'fsp_comp.c',
	'fsp_proof.c',
	'fsp_main.c',
	
    dependencies: [],
    link_with: [],
    include_directories: fsp_includes,
    install: true,
)
