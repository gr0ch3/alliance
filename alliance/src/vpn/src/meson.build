vpn_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
vex_includes = project_dict['vex_includes']
vbh_includes = project_dict['vbh_includes']

libvpn = shared_library(
    'vpn',
	'vpnfree.c',
	'vpnsearch.c',
	'vpnalloc.c',
	'vpnunion.c',
	'vpnsimp.c',
	'vpnview.c',
	'vpndel.c',
	'vpnget.c',
	'toto.c',
	'vpnenv.c',
	'vpnerror.c',
	'vpnadd.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		vpn_includes,
		mbk_includes,
		aut_includes,
		vex_includes,
		vbh_includes
	],
    install: true,
)

libmbk = project_dict['libmbk']
libaut = project_dict['libaut']
libvex = project_dict['libvex']
libvbh = project_dict['libvbh']

vpn = executable(
    'vpn',
	'main.c',
	
    dependencies: [],
    link_with: [libvpn, libmbk, libaut, libvex, libvbh],
    include_directories: [
		vpn_includes,
		mbk_includes,
		aut_includes,
		vex_includes,
		vbh_includes
	],
    install: true,
)

project_dict += {'libvpn': libvpn}
