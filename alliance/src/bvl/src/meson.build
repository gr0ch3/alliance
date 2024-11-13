bvl_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
log_includes = project_dict['log_includes']
beh_includes = project_dict['beh_includes']
bhl_includes = project_dict['bhl_includes']

libbvl = shared_library(
    'bvl',
	'bvl_drive.c',
	'bvl_util.c',
	'bvl_globals.c',
	'bvl_parse.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
      bvl_includes,
      mbk_includes,
      log_includes,
      beh_includes,
      bhl_includes
    ],
    install: true,
)

project_dict += {'libbvl': libbvl}
