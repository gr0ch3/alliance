mbk_includes = include_directories(
  '.'
)

aut_includes = project_dict['aut_includes']

libmbk = shared_library(
    'mbk',
    'mbk_util.c',
    'spi_parse.c',
    'vel_o.c',
    'vel_drive.c',
    'drive_vti_p.c',
    'spi_global.c',
    'gen_print.c',
    'vel_vect.c',
    'spi_drive.c',
    'drive_vti_l.c',
    'mbk_sys.c',
    'spi_msg.c',
    'alc_driv_p.c',
    'drive_hilo.c',
    'mvl_sspec.c',
    'x2vy_main.c',
    'alc_pars_l.c',
    'vel_chain.c',
    'alc_pars_p.c',
    'mbk_ph_util.c',
    'alc_driv_l.c',
    'drive_vlog.c',
    'vel_util.c',
    'mbk_lo.c',
    'mvl_drive.c',
    'time.c',
    'mbk2mg.c',
    'mvl_parse.c',
    'rcn_lo.c',
    'mbk_lo_util.c',
    'spi_int.c',
    'mbk_ph.c',
    'alc_pars_l6.c',
    'mvl_util.c',
    'parse_vti_p.c',
    'vel_sort.c',
    'spi_hash.c',
    'rcn_lo_util.c',
    'driver.c',
    'gen_generic.c',
    'parse_vti_l.c',

  dependencies: [],
  include_directories: [mbk_includes, aut_includes],
  install: true,
)

project_dict += {'libmbk': libmbk}
