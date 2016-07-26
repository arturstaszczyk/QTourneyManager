TEMPLATE = app

QT += qml quick multimedia
CONFIG += c++11

SOURCES += main.cpp \
    Features/Timer/TimerModel.cpp \
    Features/RoundDef.cpp \
    Features/NavigationBar/NavigationBarController.cpp \
    Features/TournamentStructureDef.cpp \
    Commands/RequestTournamentsCommand.cpp \
    Commands/CommandRecycler.cpp \
    Commands/RequestRoundsCommand.cpp \
    Features/Timer/TimerController.cpp \
    Features/Tournaments/TournamentsListController.cpp \
    Commands/RequestPlayersCommand.cpp \
    Features/PlayersAndStats/PlayersAndStatsController.cpp \
    Features/PlayersAndStats/PlayersModel.cpp \
    Commands/RequestBuyinCommand.cpp \
    Features/PlayerDef.cpp \
    Features/Settings/SettingsController.cpp \
    Features/Settings/SettingsModel.cpp \
    Commands/UpdatePlayerCommand.cpp

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
    Features/Tournaments/TournamentsListModel.h \
    Features/NavigationBar/NavigationBarModel.h \
    Features/NavigationBar/NavigationBarController.h \
    Commands/Command.h \
    Commands/CommandRecycler.h \
    Commands/RequestRoundsCommand.h \
    Commands/RequestTournamentsCommand.h \
    Features/Timer/TimerController.h \
    Features/Tournaments/TournamentsListController.h \
    Features/PlayerDef.h \
    Features/BuyinDef.h \
    Commands/RequestPlayersCommand.h \
    Features/PlayersAndStats/PlayersAndStatsController.h \
    Features/PlayersAndStats/PlayersModel.h \
    Features/PlayersAndStats/StatsModel.h \
    Commands/RequestBuyinCommand.h \
    Features/Settings/SettingsModel.h \
    Features/Settings/SettingsController.h \
    Commands/UpdatePlayerCommand.h
