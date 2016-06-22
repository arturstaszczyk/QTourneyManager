TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Timer/TimerModel.cpp \
    Timer/TimerLogic.cpp \
    RoundDef.cpp \
    Settings/HostAddress/HostAddressModel.cpp \
    Settings/HostAddress/HostAddressLogic.cpp \
    Tournaments/TounramentsListModel.cpp

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
    QAutoProperty.h \
    Timer/TimerModel.h \
    Timer/TimerLogic.h \
    RoundDef.h \
    ReturnIf.h \
    Settings/HostAddress/HostAddressModel.h \
    Settings/HostAddress/HostAddressLogic.h \
    QSortHelpers.h \
    Tournaments/TounramentsListModel.h
