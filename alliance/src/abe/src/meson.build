abe_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']
bdd_includes = project_dict['bdd_includes']
abv_includes = project_dict['abv_includes']
abt_includes = project_dict['abt_includes']

libabe = shared_library(
    'abe',
	'beh_view.c',
	'beh_del.c',
	'beh_rmv.c',
	'beh_fre.c',
	'beh_message.c',
	'main.c',
	'beh_add.c',
	'beh_getgenva.c',
	'beh_toolbug.c',
	'beh_dict.c',
	'beh_error.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		abe_includes,
		mbk_includes,
		aut_includes,
		abl_includes,
		bdd_includes,
		abv_includes,
		abt_includes
	],
    install: true,
)

project_dict += {'libabe': libabe}
