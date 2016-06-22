import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

import "Globals.js" as Globals
import "Timer"
import "Settings"

ApplicationWindow {
    visible: true
    width: 640
    height: 960
    id: app

    menuBar: MenuBar {

        Menu {
            title: qsTr("Start")
            MenuItem {
                text: qsTr("Show tournaments");
            }

            MenuItem {
                text: qsTr("Show timer");
                onTriggered: root.state = "Timer"
            }

            MenuItem {
                text: qsTr("Show menu")
                onTriggered: root.state = "Menu"
            }
        }

        Menu {
            title: qsTr("Settings")
            MenuItem {
                text: qsTr("&Set host")
                onTriggered: hostSettings.open()
            }
        }
    }

    Dialog {
        id: hostSettings
        HostAddressSetting {
            id:hostSettingsContent
        }

        onAccepted: hostAddressController.onHostAddressChanged(hostSettingsContent.address,
                                                               hostSettingsContent.valid)
    }


    Rectangle {
        id: root
        anchors.fill: parent
        color: Globals.appBackground

        Keys.onReleased: {
            if (event.key === Qt.Key_Back || event.key === Qt.Key_Escape) {
                stackView.back(event);
            }
        }

        Loader {
            anchors.fill: parent
            id: content
        }

        states: [
            State {
                name: "Timer"
                PropertyChanges {
                    target: content
                    source: "qrc:/qml/Timer/Timer.qml"
                }
            },

            State {
                name: "Tournaments"
                PropertyChanges {
                    target: content
                    source: ""
                }
            },

            State {
                name: "Menu"
                PropertyChanges {
                    target: content
                    source: "qrc:/qml/BlindsEditor/BlindsListEditor.qml"
                }
            }

        ]
    }
}
