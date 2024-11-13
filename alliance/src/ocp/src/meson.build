ocp_includes = include_directories(
    'common',
	'placer',
)

ocp = shared_library(
    'ocp',
	'common/PCommon.cpp',
	'common/PPos.cpp',
	'common/PBBox.cpp',
	'placer/PElem.cpp',
	'placer/PPlacementFinal.cpp',
	'placer/PDetSubRow.cpp',
	'placer/PDetPlacement.cpp',
	'placer/PPlacement.cpp',
	'placer/PFixedIns.cpp',
	'placer/Ocp.cpp',
	'placer/PNet.cpp',
	'placer/PBin.cpp',
	'placer/PCon.cpp',
	'placer/PToPlaceIns.cpp',
	'placer/PPlacementGlobal.cpp',
	'placer/PIns.cpp',
	'placer/PRow.cpp',
	'placer/PDetToPlaceIns.cpp',
	'placer/PSubRow.cpp',
	'placer/PONet.cpp',
	'placer/PMove.cpp',
	
    dependencies: [],
    link_with: [],
    include_directories: ocp_includes,
    install: true,
)
