aut_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']

libaut = shared_library(
	'aut',
	'authash.c',
	'authash2.c',
	'autexit.c',
	'autsort.c',
	'autalloc.c',
	'autdebug.c',
	'auterror.c',
	'autenv.c',
	'autresize.c',
	'autname.c',
	'autfree.c',
	'autgraph.c',
	'testhash.c',
	'auttest.c',
    dependencies: [],
    link_with: [],
    include_directories: [aut_includes, mbk_includes],
    install: true,
)

libmbk = project_dict['libmbk']

executable(
    'auttest',
	'main.c',
    dependencies: [],
    link_with: [libaut, libmbk],
    include_directories: [aut_includes, mbk_includes],
    install: true,
)

project_dict += {'libaut': libaut}
