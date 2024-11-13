mocha_includes = include_directories(
    '.',
)

mocha = shared_library(
    'mocha',
	'mocha_shared.c',
	'mocha_debug.c',
	'mocha_fsm.c',
	'mocha_ctl.c',
	'mocha_bdd.c',
	'mocha_check.c',
	'mocha_main.c',
	'mocha_syf.c',
	'mocha_beh.c',
	
    dependencies: [],
    link_with: [],
    include_directories: mocha_includes,
    install: true,
)
