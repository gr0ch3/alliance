s2r_includes = include_directories(
    '.',
)

s2r = shared_library(
    's2r',
	'statistics.c',
	'postrat.c',
	'hash.c',
	'main.c',
	'rdsx2y.c',
	'rdsacces.c',
	'merge.c',
	
    dependencies: [],
    link_with: [],
    include_directories: s2r_includes,
    install: true,
)
