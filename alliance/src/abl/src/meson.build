abl_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']

libabl = shared_library(
    'abl',
	'ablpolar.c',
	'abldev.c',
	'abldup.c',
	'ablfree.c',
	'ablunflat.c',
	'ablsimp.c',
	'ablvhdl.c',
	'abladd.c',
	'ablmap.c',
	'ablctlnorm.c',
	'abloptim.c',
	'ablview.c',
	'ablenv.c',
	'ablcreate.c',
	'ablsubst.c',
	'main.c',
	'ablget.c',
	'abldel.c',
	'ablstr.c',
	'ablflat.c',
	'ablis.c',
	'ablctlsimp.c',
	'ablerror.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [abl_includes, mbk_includes, aut_includes],
    install: true,
)

project_dict += {'libabl': libabl}
