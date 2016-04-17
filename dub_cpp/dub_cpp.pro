TEMPLATE = lib
CONFIG += staticlib

DISTFILES += \
    dub.json \
    source/dub_cpp/dub_cpp.d

DEPENDFILES=$$PWD/dub.json \
$$PWD/source/dub_cpp/dub_cpp.d

message($$DEPENDFILES)

dubBuild.target = $$PWD/libdub_cpp.a
dubBuild.depends = $$DEPENDFILES
dubBuild.commands = cd $$PWD; dub build

PRE_TARGETDEPS += $$PWD/libdub_cpp.a
QMAKE_EXTRA_TARGETS += dubBuild
