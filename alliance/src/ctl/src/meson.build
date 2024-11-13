ctl_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
vex_includes = project_dict['vex_includes']

libctl = shared_library(
    'ctl',
	'ctlerror.c',
	'ctlview.c',
	'ctldel.c',
	'ctlfree.c',
	'ctlsearch.c',
	'ctladd.c',
	'ctlenv.c',
	'ctlalloc.c',
	
    dependencies: [],
    link_with: [],
	include_directories: [
		ctl_includes,
		mbk_includes,
		aut_includes,
		vex_includes
	],
    install: true,
)

project_dict += {'libctl': libctl}
