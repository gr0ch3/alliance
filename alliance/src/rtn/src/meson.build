rtn_includes = include_directories(
    '.',
)

rtn = shared_library(
    'rtn',
	'rtndel.c',
	'rtnget.c',
	'rtnalloc.c',
	'rtnsearch.c',
	'rtnadd.c',
	'rtnfree.c',
	'main.c',
	'rtnerror.c',
	'rtnview.c',
	
    dependencies: [],
    link_with: [],
    include_directories: rtn_includes,
    install: true,
)
