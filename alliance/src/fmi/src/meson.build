fmi_includes = include_directories(
    '.',
)

fmi = shared_library(
    'fmi',
	'fmi_main.c',
	'fmi_optim.c',
	'fmi_bdd.c',
	'fmi_parse.c',
	
    dependencies: [],
    link_with: [],
    include_directories: fmi_includes,
    install: true,
)
