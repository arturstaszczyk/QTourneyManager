import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

import "Globals.js" as Globals
import "MainMenu"
import "Timer"
import "Settings"

ApplicationWindow {
    visible: true
    width: 640
    height: 960

    menuBar: MenuBar {
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

        Rectangle {
            Label {
                text: "bla"
            }
        }

        Timer {
            anchors.fill: parent
            visible: true//hostAddressModel.isValid
        }

    }
}
