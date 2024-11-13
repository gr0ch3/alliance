sea_includes = include_directories(
    '.',
)

sea = shared_library(
    'sea',
	'DEF_drive.c',
	'DEF_actions.c',
	'util_Power.c',
	'a2DEF.c',
	'debug.c',
	'util_RTU.c',
	'util_Floorplan.c',
	'util_LEFDEF.c',
	'util_Inter.c',
	'MAC_drive.c',
	'util_MBK.c',
	'util_Sys.c',
	'DEF2a.c',
	'sxlib2LEF.c',
	'LEF_drive_sxlib.c',
	'LEF_drive.c',
	
    dependencies: [],
    link_with: [],
    include_directories: sea_includes,
    install: true,
)
