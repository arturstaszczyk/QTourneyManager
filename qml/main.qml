import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

import "Globals.js" as Globals
import "MainMenu"
import "MainScreen"
import "Settings"

ApplicationWindow {
    visible: true
    width: 640
    height: 960

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Set host")
                onTriggered: hostSetting.open()
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Dialog {
        id: hostSetting
        HostAddressSetting {
            id:address
        }

        onAccepted: addressModel.address = address.text
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

        MainScreen {
            anchors.fill: parent
        }

    }
}
