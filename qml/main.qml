import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

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
                onTriggered: stackView.push("qrc:/qml/Tounraments/Tournaments.qml")
            }

            MenuItem {
                text: qsTr("Show timer");
                onTriggered: stackView.push("qrc:/qml/Timer/Timer.qml")
            }

            MenuItem {
                text: qsTr("Show menu")
                onTriggered: stackView.push("qrc:/qml/BlindsEditor/BlindsListEditor.qml")
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

    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                iconSource: "qrc:/images/icons-basic-ui/left224.png"
                onClicked: stackView.pop()
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


    StackView {
        id: stackView
        width: parent.width
        height: parent.height
        initialItem: root

        Rectangle {
            id: root
            width: parent.width
            height: parent.height
            color: Globals.appBackground
        }
    }
}
