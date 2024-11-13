druc_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
rds_includes = project_dict['rds_includes']

yacc_generated = custom_target('yacc_generated',
	depend_files: 'drucompi_y.y',
	input: 'drucompi_y.y',
	output: ['drucompi_y_c', 'drucompi_y_h'],
	command: [yacc, '-o', '@OUTPUT0@', '--defines=@OUTPUT1@', '@INPUT@'],
)

drucompi_y_h = custom_target('drucompi_y_h',
	depends: yacc_generated,
	input: yacc_generated,
    output: 'drucompi_y.h',
    command: [sed, '-e', 's/yy/vrd_y_/g', '-e', 's/YY/VRD_Y_/g', '@INPUT1@'],
    capture: true
)

drucompi_y_c = custom_target('drucompi_y_c',
	depends: [yacc_generated, drucompi_y_h],
	input: yacc_generated,
    output: 'drucompi_y.c',
    command: [sed, '-e', 's/yy/vrd_y_/g', '-e', 's/YY/VRD_Y_/g', '@INPUT0@'],
    capture: true
)

drucompi_lex_c = custom_target('drucompi_lex_c',
	depend_files: 'drucompi_l.l',
	input: 'drucompi_l.l',
	output: 'drucompi_l_c',
	command: [lex, '-o', '@OUTPUT@', '@INPUT@'],
)

drucompi_l_c = custom_target('drucompi_l_c',
	depends: drucompi_lex_c,
	input: drucompi_lex_c,
    output: 'drucompi_l.c',
    command: [sed, '-e', 's/yy/vrd_y_/g', '-e', 's/YY/VRD_Y_/g', '@INPUT@'],
    capture: true
)

libdruc = shared_library(
    'druc',
	drucompi_y_c,
	drucompi_l_c,
	'defunion.c',
	'definclu.c',
	'defexclu.c',
	'druchier.c',
	'vmcrelat.c',
	'deftools.c',
	'drucutil.c',
	'vmcasmld.c',
	'vmcaract.c',
	'vmcerror.c',
	'drucgral.c',
	'defdefin.c',
	'defresiz.c',
	'drucmin.c',
	'vmcmesur.c',
	'drucompi.c',
	'definter.c',
	'drucring.c',
	'vmctools.c',
	'vmcunify.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		druc_includes,
		mbk_includes,
		rds_includes
	],
    install: true,
)

druc = executable(
    'druc',
	'drucbath.c',
	
    dependencies: [],
    link_with: [libdruc],
    include_directories: [
		druc_includes,
		mbk_includes,
		rds_includes
	],
    install: true,
)

drucgral_test = executable(
    'drucgral_test',
	'drucgral_test.c',
	
    dependencies: [],
    link_with: [libdruc],
    include_directories: [
		druc_includes,
		mbk_includes,
		rds_includes
	],
    install: true,
)

project_dict += {'libdruc': libdruc}
