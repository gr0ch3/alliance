genlib_includes = include_directories(
    '.',
)

genlib = shared_library(
    'genlib',
	'genlib.c',
	'dpgen_RF1.c',
	'dpgen_Regular.c',
	'dpgen_ROM.c',
	'util_Const.c',
	'dpgen_uROM.c',
	'dpgen_Adder.c',
	'dpgen_RF2.c',
	'dpgen_RAM.c',
	'dpgen_Macro.c',
	'util_Misc.c',
	'util_Genlib.c',
	'util_Sys.c',
	'dpgen_Shifter.c',
	'dpgen_Nul.c',
	
    dependencies: [],
    link_with: [],
    include_directories: genlib_includes,
    install: true,
)
