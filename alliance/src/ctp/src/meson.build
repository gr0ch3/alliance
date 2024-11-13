ctp_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
vex_includes = project_dict['vex_includes']
ctl_includes = project_dict['ctl_includes']

libctp = shared_library(
    'ctp',
	'ctp_util.c',
	'ctp_parse.c',
	'ctp_bspec.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		ctp_includes,
		mbk_includes,
        aut_includes,
        vex_includes,
        ctl_includes
	],
    install: true,
)

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libctl = project_dict['libctl']
libvex = project_dict['libvex']

ctp = executable(
    'ctp',
	'main.c',
	
    dependencies: [],
    link_with: [libctp, libmbk, libaut, libctl, libvex],
    include_directories: [
		ctp_includes,
		mbk_includes,
        aut_includes,
        vex_includes,
        ctl_includes
	],
    install: true,
)

project_dict += {'libctp': libctp}
