cmake_minimum_required(VERSION 3.10)

# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/home/david/project/build-qt-creator-Desktop_Qt_5_15_2_GCC_64bit-Debug")

project(DubProject)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(QtCreator REQUIRED COMPONENTS Core)
message("find qt")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
set(QtX Qt${QT_VERSION_MAJOR})

message("QtX ${QtX}")

add_qtc_plugin(DubProject
  PLUGIN_DEPENDS
    QtCreator::Core
  DEPENDS
    ${QtX}::Widgets
    QtCreator::ExtensionSystem
    QtCreator::Utils
  SOURCES
    .github/workflows/build_cmake.yml
    .github/workflows/README.md
    README.md
    dubproject.cpp
    dubproject.h
    dubproject_global.h
    dubprojectconstants.h
)

find_program(DUB dub REQUIRED)
message("dub ${DUB}")
execute_process(COMMAND ${DUB} describe WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dub_cpp OUTPUT_VARIABLE PROJECT_DUB_JSON)

string(JSON DUB_CPP_TARGET_FILE GET ${PROJECT_DUB_JSON} packages 0 targetFileName)
string(JSON DUB_PATH GET ${PROJECT_DUB_JSON} packages 1 path)
string(JSON DUB_TARGET_PATH GET ${PROJECT_DUB_JSON} packages 1 targetPath)

message("DUB_CPP_TARGET_FILE ${DUB_CPP_TARGET_FILE} ${DUB_PATH} ${DUB_TARGET_PATH}")
find_program(DMD dmd REQUIRED)
execute_process(COMMAND ${DMD} test -v OUTPUT_VARIABLE DMD_VERBOSE ERROR_VARIABLE DMD_ERR)
string(REGEX REPLACE ".*-L-L([.a-zA-Z0-9/_\-]*).*" "\\1" DMD_PATH ${DMD_VERBOSE})
message("DMD_PATH ${DMD_PATH}")

#
set(DUB_CPP_FILES
    dub_cpp/dub.json
    dub_cpp/source/DProject.d
)

set(DUB_CPP_LIB ${CMAKE_CURRENT_SOURCE_DIR}/dub_cpp/${DUB_CPP_TARGET_FILE})
add_custom_command(OUTPUT ${DUB_CPP_LIB} COMMAND dub build dub --config library COMMAND ${DUB} build DEPENDS ${DUB_CPP_FILES} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dub_cpp)
add_custom_target(DUB_CPP DEPENDS ${DUB_CPP_LIB} COMMENT "Build DUB_CPP")

target_link_libraries(DubProject PUBLIC dub_cpp phobos2 dub)
target_link_directories(DubProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/dub_cpp "${DUB_PATH}${DUB_TARGET_PATH}" ${DMD_PATH})
add_dependencies(DubProject DUB_CPP)
