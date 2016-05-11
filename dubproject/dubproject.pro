DEFINES += DUBPROJECT_LIBRARY

# DubProject files

SOURCES += dubprojectplugin.cpp \
    d_initializer.cpp \
    dubprojectmanager.cpp \
    dubproject.cpp \
    dubfile.cpp \
    dubprojectprojectnode.cpp

HEADERS += dubprojectplugin.h \
        dubproject_global.h \
        dubprojectconstants.h \
    d_initializer.h \
    dubprojectmanager.h \
    dubproject.h \
    dubfile.h \
    dubprojectprojectnode.h

# Qt Creator linking

## set the QTC_SOURCE environment variable to override the setting here
QTCREATOR_SOURCES = $$(QTC_SOURCE)
isEmpty(QTCREATOR_SOURCES):QTCREATOR_SOURCES=/home/feurleda/projects/qt-creator

## set the QTC_BUILD environment variable to override the setting here
IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE):IDE_BUILD_TREE=/home/feurleda/projects/build-qtcreator-Desktop_Qt_5_6_0_GCC_64bit-Debug

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on Mac
# USE_USER_DESTDIR = yes

###### If the plugin can be depended upon by other plugins, this code needs to be outsourced to
###### <dirname>_dependencies.pri, where <dirname> is the name of the directory containing the
###### plugin's sources.

QTC_PLUGIN_NAME = DubProject
QTC_LIB_DEPENDS += \
    # nothing here at this time

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    projectexplorer

QTC_PLUGIN_RECOMMENDS += \
    # optional plugin dependencies. nothing here at this time

###### End _dependencies.pri contents ######

include($$QTCREATOR_SOURCES/src/qtcreatorplugin.pri)

LIBS += -L$$PWD/../dub_cpp/ -ldub_cpp -lphobos2
LIBS += -L$$(HOME)/.dub/packages/dub-master/bin -ldub
PRE_TARGETDEPS += $$PWD/../dub_cpp/libdub_cpp.a

RESOURCES += \
    dubproject.qrc
