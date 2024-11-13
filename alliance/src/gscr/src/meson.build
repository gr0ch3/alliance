gscr_includes = include_directories(
    '.',
)

gscr = shared_library(
    'gscr',
	'sx2sc.c',
	'gscr_AllowFree.c',
	'scp_time.c',
	'scp_main.c',
	'scp_inits.c',
	'gscr_SymbChanRout.c',
	'scp_mbk2scp.c',
	'scp_placer.c',
	'gscr_main.c',
	'scp_modif.c',
	'gscr_StaticUtil.c',
	'scp_channel.c',
	'gscr_GreedyRout.c',
	'scp_scp2mbk.c',
	'gscr_DynamicUtil.c',
	
    dependencies: [],
    link_with: [],
    include_directories: gscr_includes,
    install: true,
)
