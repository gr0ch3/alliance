project(
  'alliance',
  'c','cpp',
   version: run_command('_build_utils/version.py').stdout().strip(),
   meson_version: '>= 1.2.0',
   default_options: [
     'buildtype=debugoptimized',
     'c_std=gnu11',
     'cpp_std=gnu++17',
     'b_lundef=false',
   ],
)

cc = meson.get_compiler('c')
cpp = meson.get_compiler('cpp')

add_project_arguments(
  '-Wno-deprecated-declarations',
  '-Wno-unused-function',
  '-Wno-unused-private-field',
  '-Wno-return-type-c-linkage',
  '-Wno-unused-variable',
  '-Wno-#pragma-messages',
  '-Wno-unknown-pragmas',
  '-Wno-unused-but-set-variable',
  '-Wno-overloaded-virtual',
  language: ['c','cpp']
)

project_dict = {}

alliance_top = meson.project_source_root()

## Dependencies
py = import('python').find_installation(pure:false)
py_deps = dependency('python3', required: true)

X11 = dependency('x11', required: true)
# libx11_xcb_dev = dependency('libx11-xcb-dev', required: true)

  # for dreal
x11_dep = declare_dependency(
    include_directories: include_directories('/usr/include/X11'),
    link_args: ['-lX11']
)
  # for dreal
motif_dep = declare_dependency(
  include_directories: include_directories('/usr/include/X11'),
  link_args: ['-lXm']
)
  # for dreal
xt_dep = declare_dependency(
    include_directories: include_directories('/usr/include/X11'),
    link_args: ['-lXt']
)

  # for druc
yacc = find_program('bison')
lex = find_program('flex')

sed = find_program('sed')

## C Declarations
add_project_arguments('-DTECHNO="symbolic_cmos"', language: 'c')
# add_project_arguments('-DVERSION=' + meson.project_version(), language: 'c')  # Complains about wrong format
add_project_arguments('-DVERSION="5.1"', language: 'c')

add_project_arguments('-DALLIANCE_VERSION="5.1"', language: 'c') # for alcban

  # for rds
add_project_arguments('-DRTL_DEFAULT_TECHNO="etc/cmos.rds"', language: 'c')

  # for dreal
add_project_arguments('-DALLIANCE_TOP="' + alliance_top + '"', language: 'c')
add_project_arguments('-DDREAL_DEFAULT_TECHNO_NAME="gf180mcu_nsx2"', language: 'c')
add_project_arguments('-DPACKAGE="dreal"', language: 'c')
add_project_arguments('-DGMS_FILE_NAME="dreal"', language: 'c')
add_project_arguments('-DDREAL_WINDOW_DX="DREAL_WINDOW_DX"', language: 'c')
add_project_arguments('-DDREAL_WINDOW_DY="DREAL_WINDOW_DY"', language: 'c')
add_project_arguments('-DDREAL_WINDOW_XMIN="DREAL_WINDOW_XMIN"', language: 'c')
add_project_arguments('-DDREAL_WINDOW_YMIN="DREAL_WINDOW_YMIN"', language: 'c')
add_project_arguments('-DDREAL_WINDOW_SIDE="DREAL_WINDOW_SIDE"', language: 'c')

## Common includes; Because of cyclic dependency between some subdir ...
project_dict += {
  'mbk_includes': include_directories('alliance/src/mbk/src'),
  'aut_includes': include_directories('alliance/src/aut/src'),
  'abl_includes': include_directories('alliance/src/abl/src'),
  'bdd_includes': include_directories('alliance/src/bdd/src'),
  'abv_includes': include_directories('alliance/src/abv/src'),
  'abt_includes': include_directories('alliance/src/abt/src'),
  'abe_includes': include_directories('alliance/src/abe/src'),
  'log_includes': include_directories('alliance/src/log/src'),
  'beh_includes': include_directories('alliance/src/beh/src'),
  'pat_includes': include_directories('alliance/src/pat/src'),
  'bhl_includes': include_directories('alliance/src/bhl/src'),
  'bvl_includes': include_directories('alliance/src/bvl/src'),
  'b2f_includes': include_directories('alliance/src/b2f/src'),
  'boog_includes': include_directories('alliance/src/boog/src'),
  'boom_includes': include_directories('alliance/src/boom/src'),
  'btr_includes': include_directories('alliance/src/btr/src'),
  'ctl_includes': include_directories('alliance/src/ctl/src'),
  'ctp_includes': include_directories('alliance/src/ctp/src'),
  'dreal_includes': include_directories('alliance/src/dreal/src'),
  'druc_includes': include_directories('alliance/src/druc/src'),
  'elp_includes': include_directories('alliance/src/elp/src'),
  'exp_includes': include_directories('alliance/src/exp/src'),
  'fks_includes': include_directories('alliance/src/fks/src'),
  'flatbeh_includes': include_directories('alliance/src/flatbeh/src'),
  'flatlo_includes': include_directories('alliance/src/flatlo/src'),
  'flatph_includes': include_directories('alliance/src/flatph/src'),
  'fmi_includes': include_directories('alliance/src/fmi/src'),
  'fsm_includes': include_directories('alliance/src/fsm/src'),
  'fsp_includes': include_directories('alliance/src/fsp/src'),
  'ftl_includes': include_directories('alliance/src/ftl/src'),
  'fvh_includes': include_directories('alliance/src/fvh/src'),
  'genlib_includes': include_directories('alliance/src/genlib/src'),
  'genpat_includes': include_directories('alliance/src/genpat/src'),
  'graal_includes': include_directories('alliance/src/graal/src'),
  'gscr_includes': include_directories('alliance/src/gscr/src'),
  'k2f_includes': include_directories('alliance/src/k2f/src'),
  'l2p_includes': include_directories('alliance/src/l2p/src'),
  'loon_includes': include_directories('alliance/src/loon/src'),
  'lvx_includes': include_directories('alliance/src/lvx/src'),
  'lynx_includes': include_directories('alliance/src/lynx/src'),
  'm2e_includes': include_directories('alliance/src/m2e/src'),
  'mips_asm_includes': include_directories('alliance/src/mips_asm/src'),
  'mocha_includes': include_directories('alliance/src/mocha/src'),
  'nero_includes': include_directories('alliance/src/nero/src'),
  'ocp_includes': include_directories('alliance/src/ocp/src'),
  'pat2spi_includes': include_directories('alliance/src/pat2spi/src'),
  'proof_includes': include_directories('alliance/src/proof/src'),
  'rds_includes': include_directories('alliance/src/rds/src'),
  'ring_includes': include_directories('alliance/src/ring/src'),
  'rtd_includes': include_directories('alliance/src/rtd/src'),
  'rtn_includes': include_directories('alliance/src/rtn/src'),
  's2r_includes': include_directories('alliance/src/s2r/src'),
  'scapin_includes': include_directories('alliance/src/scapin/src'),
  'scl_includes': include_directories('alliance/src/scl/src'),
  'scr_includes': include_directories('alliance/src/scr/src'),
  'sea_includes': include_directories('alliance/src/sea/src'),
  'syf_includes': include_directories('alliance/src/syf/src'),
  'vasy_includes': include_directories('alliance/src/vasy/src'),
  'vbh_includes': include_directories('alliance/src/vbh/src'),
  'vex_includes': include_directories('alliance/src/vex/src'),
  'vpn_includes': include_directories('alliance/src/vpn/src'),
  'x2y_includes': include_directories('alliance/src/x2y/src'),
  'xfsm_includes': include_directories('alliance/src/xfsm/src'),
  'xgra_includes': include_directories('alliance/src/xgra/src'),
  'xpat_includes': include_directories('alliance/src/xpat/src'),
  'xsch_includes': include_directories('alliance/src/xsch/src'),
  'xvpn_includes': include_directories('alliance/src/xvpn/src'),
}

## Subdirectories - Warning: Order matters
subdir('alliance/src/mbk')
subdir('alliance/src/aut')
subdir('alliance/src/abl')
subdir('alliance/src/bdd')
subdir('alliance/src/abv')
subdir('alliance/src/abt')
subdir('alliance/src/abe')
subdir('alliance/src/alcban')
subdir('alliance/src/log')
subdir('alliance/src/beh')
subdir('alliance/src/pat')
subdir('alliance/src/bhl')
subdir('alliance/src/bvl')
subdir('alliance/src/asimut')
subdir('alliance/src/b2f')
subdir('alliance/src/ftl')
subdir('alliance/src/fsm')
subdir('alliance/src/boog')
subdir('alliance/src/boom')
subdir('alliance/src/ctl')
# subdir('alliance/src/btr')  # WIP: undefined reference to `missbddnodeassocon'
subdir('alliance/src/vex')
subdir('alliance/src/ctp')
subdir('alliance/src/vbh')
subdir('alliance/src/vpn')
subdir('alliance/src/k2f')
subdir('alliance/src/rds')
subdir('alliance/src/dreal')
# subdir('alliance/src/druc')  # WIP: type error after sed sub 'YY' -> 'VRD_Y_'
# subdir('alliance/src/elp')
# subdir('alliance/src/exp')
# subdir('alliance/src/fks')
# subdir('alliance/src/flatbeh')
# subdir('alliance/src/flatlo')
# subdir('alliance/src/flatph')
# subdir('alliance/src/fmi')
# subdir('alliance/src/fsp')
# subdir('alliance/src/fvh')
# subdir('alliance/src/genlib')
# subdir('alliance/src/genpat')
# subdir('alliance/src/graal')
# subdir('alliance/src/gscr')
# subdir('alliance/src/l2p')
# subdir('alliance/src/loon')
# subdir('alliance/src/lvx')
# subdir('alliance/src/lynx')
# subdir('alliance/src/m2e')
# subdir('alliance/src/mips_asm')
# subdir('alliance/src/mocha')
# subdir('alliance/src/nero')
# subdir('alliance/src/ocp')
# subdir('alliance/src/pat2spi')
# subdir('alliance/src/proof')
# subdir('alliance/src/ring')
# subdir('alliance/src/rtd')
# subdir('alliance/src/rtn')
# subdir('alliance/src/s2r')
# subdir('alliance/src/scapin')
# subdir('alliance/src/scl')
# subdir('alliance/src/scr')
# subdir('alliance/src/sea')
# subdir('alliance/src/syf')
# subdir('alliance/src/vasy')
# subdir('alliance/src/x2y')
# subdir('alliance/src/xfsm')
# subdir('alliance/src/xgra')
# subdir('alliance/src/xpat')
# subdir('alliance/src/xsch')
# subdir('alliance/src/xvpn')
