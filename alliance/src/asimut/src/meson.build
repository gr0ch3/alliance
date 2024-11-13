asimut_includes = include_directories(
  '.'
)

mbk_includes = project_dict['mbk_includes']
log_includes = project_dict['log_includes']
beh_includes = project_dict['beh_includes']
pat_includes = project_dict['pat_includes']
bhl_includes = project_dict['bhl_includes']
bvl_includes = project_dict['bvl_includes']

libasimut = shared_library(
    'asimut',
    'sch_CrtSch.c',
    'vh_lspec.c',
    'c_fsyn_sr4k_10.c',
    'sch_GoNTim.c',
    'vh_simulad.c',
    'sch_Free.c',
    'sch_error.c',
    'c_sr8k_8a.c',
    'vh_init.c',
    'c_fsyn_sr1k_1.c',
    'sch_debug.c',
    'sch_addshent.c',
    'vh_xcomm.c',
    'vh_util.c',
    'c_fsyn_sr1k_10.c',
    'sch_addshtra.c',
    'sch_inswave.c',
    'vh_debug.c',
    'sch_GetCTra.c',
    'c_fsyn_sr1k_24.c',
    'sch_rmventry.c',
    'sch_globals.c',
    'sch_message.c',
    'vh_xspec.c',
    'vh_globals.c',
    'c_sr1k_8a.c',
    'sch_hash.c',
    'sch_GetNTim.c',
    'c_hada_repondeur.c',
    'sch_SetCTim.c',
    'sch_addshwav.c',
    'c_fsyn_sr1k_56.c',
    'sch_GetCTim.c',
    'c_fsyn_sr1k_4.c',
    'beh_setdelay.c',
    'sch_insentry.c',
    'c_sr1k_8b.c',
    'sch_bug.c',
    'sch_AddTra.c',

    dependencies: [],
    link_with: [],
    include_directories: [
      asimut_includes,
      mbk_includes,
      log_includes,
      beh_includes,
      pat_includes,
      bhl_includes,
      bvl_includes
    ],
    install: true,
)

project_dict += {'libasimut': libasimut}
