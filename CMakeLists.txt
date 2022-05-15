cmake_minimum_required(VERSION 3.8)
project(ChordChart)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib/x64")
endif (WIN32)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Werror=return-type")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main ${SOURCE_FILES} components/chord-chart/chordChart.h components/chord-chart/chordChart.cpp components/cof/cof.h
                                    components/cof/cof.cpp components/primitiveShapes/circle.h components/primitiveShapes/circle.cpp
                                    components/primitiveShapes/cone.h components/primitiveShapes/cone.cpp components/primitiveShapes/rect.cpp
                                    components/primitiveShapes/rect.cpp components/primitiveShapes/shape.h components/primitiveShapes/shape.cpp
                                    models/scales.h models/scales.cpp models/chords.h models/chords.cpp)

if (WIN32)
    target_link_libraries (main ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (main ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()