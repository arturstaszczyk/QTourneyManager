TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Models/RoundModel.cpp \
    sources/MainScreenController.cpp \
    Models/TournamentStructureModel.cpp \
    Models/AddressModel.cpp

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
    Models/BlindsModel.h \
    Models/RoundModel.h \
    sources/MainScreenController.h \
    Models/TournamentStructureModel.h \
    Models/AddressModel.h \
    QAutoProperty.h
