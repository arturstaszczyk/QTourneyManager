TEMPLATE = app

QT += qml quick multimedia
CONFIG += c++11

SOURCES += main.cpp \
    Features/Timer/TimerModel.cpp \
    Features/RoundDef.cpp \
    Features/Settings/HostAddress/HostAddressModel.cpp \
    Features/Tournaments/TournamentsListModel.cpp \
    Features/NavigationBar/NavigationBarModel.cpp \
    Features/NavigationBar/NavigationBarController.cpp \
    Features/TournamentStructureDef.cpp \
    Commands/RequestTournamentsCommand.cpp \
    Commands/CommandRecycler.cpp \
    Commands/Command.cpp \
    Commands/RequestRoundsCommand.cpp \
    Features/Settings/HostAddress/HostAddressController.cpp \
    Features/Timer/TimerController.cpp \
    Features/Tournaments/TournamentsListController.cpp \
    PlayerDef.cpp \
    BuyinDef.cpp \
    Commands/RequestPlayersCommand.cpp

CONFIG(debug, debug|release)
{
    DEFINES += _DEBUG
}

RESOURCES += Resources/qml.qrc \
    Resources/images.qrc \
    Resources/sounds.qrc

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
    ReturnIf.h \
    QSortHelpers.h \
    AppExceptions.h \
    Features/RoundDef.h \
    Features/TournamentStructureDef.h \
    Features/Timer/TimerModel.h \
    Features/Settings/HostAddress/HostAddressModel.h \
    Features/Tournaments/TournamentsListModel.h \
    Features/NavigationBar/NavigationBarModel.h \
    Features/NavigationBar/NavigationBarController.h \
    Commands/Command.h \
    Commands/CommandRecycler.h \
    Commands/RequestRoundsCommand.h \
    Commands/RequestTournamentsCommand.h \
    Features/Settings/HostAddress/HostAddressController.h \
    Features/Timer/TimerController.h \
    Features/Tournaments/TournamentsListController.h \
    PlayerDef.h \
    BuyinDef.h \
    Commands/RequestPlayersCommand.h
