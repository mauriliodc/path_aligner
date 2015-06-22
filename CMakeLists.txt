cmake_minimum_required (VERSION 2.6 FATAL_ERROR)
SET(CMAKE_BUILD_TYPE Debug)
project      (viewerbase)
find_package (Qt4 REQUIRED)
include_directories(/usr/include/eigen3)
#needed for qglviewer
find_package (Qt4 COMPONENTS QtCore QtXml QtOpenGL QtGui)
set  (project_SOURCES main.cpp viewport.cpp window.cpp actor.h path.h path.cpp)
set  (project_HEADERS window.h viewport.h )
set  (project_FORMS   window.ui)

QT4_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT4_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})

INCLUDE         (${QT_USE_FILE})
ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE  (viewerbase ${project_SOURCES}
                            ${project_FORMS_HEADERS}
                            ${project_HEADERS_MOC})

TARGET_LINK_LIBRARIES (viewerbase QGLViewer ${QT_LIBRARIES}  GL GLU )
