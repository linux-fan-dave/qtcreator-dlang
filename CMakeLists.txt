cmake_minimum_required(VERSION 3.10)

# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/home/david/project/build-qt-creator-Desktop_Qt_5_15_2_GCC_64bit-Debug")

project(DubProject)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(QtCreator REQUIRED COMPONENTS Core)
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
set(QtX Qt${QT_VERSION_MAJOR})

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

target_link_libraries(DubProject PUBLIC dub_cpp phobos2 dub)
target_link_directories(DubProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/dub_cpp /home/david/.dub/packages/dub-1.28.0/dub/bin/)
#add_dependencies(DubProject ${CMAKE_CURRENT_SOURCE_DIR}/dub_cpp/libdub_cpp.a)
