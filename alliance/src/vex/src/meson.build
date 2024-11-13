vex_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']

libvex = shared_library(
    'vex',
	'vexsimp.c',
	'vexalloc.c',
	'vexfree.c',
	'vexdel.c',
	'vexis.c',
	'vexcreate.c',
	'vexextend.c',
	'vexview.c',
	'vexoptim.c',
	'vexget.c',
	'vexshift.c',
	'vexeval.c',
	'vexenv.c',
	'vexslice.c',
	'vexadd.c',
	'vexunflat.c',
	'vexdup.c',
	'vexerror.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		vex_includes,
		mbk_includes,
		aut_includes
	],
    install: true,
)

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']

vex = executable(
    'vex',
	'main.c',
	
    dependencies: [],
    link_with: [libvex, libmbk, libaut],
    include_directories: [
		vex_includes,
		mbk_includes,
		aut_includes
	],
    install: true,
)

project_dict += {'libvex': libvex}
