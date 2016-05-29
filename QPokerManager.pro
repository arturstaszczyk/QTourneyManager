TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    sources/BlindsDef.cpp \
    sources/GameContext.cpp \
    sources/RoundDef.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

CONFIG += c++11 warn_on rtti exceptions

macx {
    QMAKE_MAC_SDK = macosx10.11
}

HEADERS += \
    sources/BlindsDef.h \
    sources/GameContext.h \
    sources/RoundDef.h
