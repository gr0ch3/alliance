rds_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']

librds = shared_library(
    'rds',
	'rdsdel.c',
	'cif_parse.c',
	'rwiget.c',
	'rtlenv.c',
	'rprparse.c',
	'rwidel.c',
	'rwiview.c',
	'rdsalloc.c',
	'cif_drive.c',
	'rwierror.c',
	'rwifree.c',
	'cif_error.c',
	'gds_swap.c',
	'rwibuild.c',
	'rutunify.c',
	'rprerror.c',
	'rwidestroy.c',
	'gds_error.c',
	'rdsadd.c',
	'rwialloc.c',
	'rutequi.c',
	'rwiadd.c',
	'rdsview.c',
	'rdsdebug.c',
	'rdsfree.c',
	'ruterror.c',
	'rdserror.c',
	'rutacces.c',
	'gds_parse.c',
	'prout.c',
	'rfmacces.c',
	'rtlacces.c',
	'gds_drive.c',
	'rtlerror.c',
	'rfmerror.c',
	'rfmview.c',
	'rprview.c',
	'rutpoly.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		rds_includes,
		mbk_includes,
	],
    install: true,
)

libmbk = project_dict['libmbk']

rds = executable(
    'rds',
	'main.c',
	
    dependencies: [],
    link_with: [librds, libmbk],
    include_directories: [
		rds_includes,
		mbk_includes,
	],
    install: true,
)

project_dict += {'librds': librds}
