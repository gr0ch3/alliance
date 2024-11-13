bdd_includes = include_directories(
    '.',
)

mbk_includes = project_dict['mbk_includes']
aut_includes = project_dict['aut_includes']
abl_includes = project_dict['abl_includes']

libbdd = shared_library(
    'bdd',
	'bddimply.c',
	'bddcompose.c',
	'bddtransfert.c',
	'bddsystem.c',
	'bddreorder.c',
	'bddcheck.c',
	'bddcofactor.c',
	'bddfraction.c',
	'bddvar.c',
	'bddblock.c',
	'bddsweep.c',
	'bddapply.c',
	'bddreduce.c',
	'bddexplosion.c',
	'bddvaraux.c',
	'bdduser.c',
	'bddalloc.c',
	'bddresize.c',
	'bddcircuit.c',
	'bddenv.c',
	'bdderror.c',
	'bddconvert.c',
	'bddsatisfy.c',
	'main.c',
	'bddflag.c',
	'bddheath.c',
	'bddtest.c',
	'bddsupport.c',
	'bddref.c',
	'bddnode.c',
	'bddexist.c',
	'bddhnode.c',
	'bddfree.c',
	'bddsimpdc.c',
	'bdddump.c',
	'bddoptimize.c',
	'bddgarbage.c',
	'bddrelprod.c',
	'bddsubst.c',
	'bddlog.c',
	'bddassoc.c',
	'bddhoper.c',
	'bddmark.c',
	
    dependencies: [],
    link_with: [],
    include_directories: [
		bdd_includes,
		mbk_includes,
		aut_includes,
		abl_includes
	],
    install: true,
)

project_dict += {'libbdd': libbdd}
