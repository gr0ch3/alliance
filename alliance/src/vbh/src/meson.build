vbh_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
vex_includes = project_dict['vex_includes']
vpn_includes = project_dict['vpn_includes']

libvbh = shared_library(
    'vbh',
	'vpd_drive.c',
	'vbl_util.c',
	'vtlacces.c',
	'vpd_parse.c',
	'vtlerror.c',
	'vvh_vbh2vpn.c',
	'vbh_dup.c',
	'vbl_parse.c',
	'vbh_add.c',
	'vpd_error.c',
	'vbl_bspec.c',
	'vbh_crt.c',
	'vvh_drive.c',
	'vvh_parse.c',
	'vbh_view.c',
	'vbh_fre.c',
	'vbh_simp.c',
	'vvh_error.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		vbh_includes,
		mbk_includes,
		aut_includes,
		vex_includes,
		vpn_includes
	],
    install: true,
)

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libvex = project_dict['libvex']

vbh = executable(
    'vbh',
	'main.c',
	
    dependencies: [],
    link_with: [libvbh, libmbk, libaut, libvex],
    include_directories: [
		vbh_includes,
		mbk_includes,
		aut_includes,
		vex_includes,
		vpn_includes
	],
    install: true,
)

project_dict += {'libvbh': libvbh}
