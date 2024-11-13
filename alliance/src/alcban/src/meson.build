alcban_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']

libalcban = shared_library(
    'alcban',
	'alcbanner.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [alcban_includes, mbk_includes],
    install: true,
)

project_dict += {'libalcban': libalcban}
