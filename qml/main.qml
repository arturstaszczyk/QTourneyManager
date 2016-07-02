import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import "Globals.js" as Globals

import "Timer"
import "Styles"
import "Settings"
import "Tounraments"

ApplicationWindow {
    visible: true
    width: 640
    height: 960
    id: app

    property bool isCppAvailable: typeof _cpp !== "undefined"
    property QtObject _hostAddress;
    property QtObject _timer

    MockModels{
    }

    Component {
        id: tournaments
        Tournaments {}
    }

    Component{
        id: timer
        Timer {
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

    menuBar: MenuBar {
        Menu {
            title: qsTr("Go to...")
            MenuItem {
                text: qsTr("Show tournaments");
                onTriggered: {
                    stackView.push(tournaments)
                }
            }

            MenuItem {
                text: qsTr("Show timer");
                onTriggered: stackView.push(timer)
            }

//            MenuItem {
//                text: qsTr("Show menu")
//                onTriggered: stackView.push("qml/BlindsEditor/BlindsListEditor.qml")
//            }
        }



        Menu {
            title: qsTr("Settings...")
            MenuItem {
                text: qsTr("&Set host")
                onTriggered: hostSettings.open()
            }
        }
    }

    Image {
        id: background
        anchors.fill: parent
        source: "../images/poker.jpg"
        fillMode: Image.PreserveAspectCrop
    }

    ColumnLayout
    {
        anchors.fill: parent
        spacing: 0

        NavigationBar {
            Layout.fillWidth: true
        }

        StackView {
            id: stackView
            Layout.fillWidth: true
            Layout.fillHeight: true
            initialItem: root

            Rectangle {
                id: root
                color: "transparent"
            }
        }
    }
}
