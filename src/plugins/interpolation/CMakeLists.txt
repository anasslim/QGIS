########################################################
# Files

SET (INTERPOLATION_SRCS
     qgsinterpolationplugin.cpp
     qgsidwinterpolatordialog.cpp
     qgsinterpolationdialog.cpp
     qgsinterpolatordialog.cpp
     qgstininterpolatordialog.cpp
)

SET (INTERPOLATION_UIS
    qgsidwinterpolatordialogbase.ui
    qgsinterpolationdialogbase.ui
    qgstininterpolatordialogbase.ui
    )

SET (INTERPOLATION_MOC_HDRS
     qgsinterpolationplugin.h
     qgstininterpolatordialog.h
     qgsidwinterpolatordialog.h
     qgsinterpolationdialog.h
     qgsinterpolatordialog.h
)

SET (INTERPOLATION_RCCS  interpolator.qrc)
########################################################
# Build

QT5_WRAP_UI (INTERPOLATION_UIS_H  ${INTERPOLATION_UIS})

QT5_WRAP_CPP (INTERPOLATION_MOC_SRCS  ${INTERPOLATION_MOC_HDRS})

QT5_ADD_RESOURCES(INTERPOLATION_RCC_SRCS ${INTERPOLATION_RCCS})

ADD_LIBRARY (interpolationplugin MODULE
  ${INTERPOLATION_SRCS}
  ${INTERPOLATION_MOC_SRCS}
  ${INTERPOLATION_RCC_SRCS}
  ${INTERPOLATION_UIS_H})

INCLUDE_DIRECTORIES(SYSTEM
     ${GEOS_INCLUDE_DIR}
)

INCLUDE_DIRECTORIES(
     ${CMAKE_CURRENT_BINARY_DIR}
     ../../analysis/interpolation
     ../../core
     ../../core/geometry
     ../../core/raster
     ../../gui
     ..
     .
)

TARGET_LINK_LIBRARIES(interpolationplugin
  qgis_analysis
  qgis_core
  qgis_gui
)


########################################################
# Install

INSTALL(TARGETS interpolationplugin
  RUNTIME DESTINATION ${QGIS_PLUGIN_DIR}
  LIBRARY DESTINATION ${QGIS_PLUGIN_DIR}
  )
