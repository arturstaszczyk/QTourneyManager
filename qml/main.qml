import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import "Globals.js" as Globals
import "Timer"
import "Settings"
import "Styles"

ApplicationWindow {
    visible: true
    width: 640
    height: 960
    id: app

    property bool isCppAvailable: typeof _cpp !== "undefined"

    property QtObject _hostAddress: hostAddressModel

    MockModels{

    }

    menuBar: MenuBar {

        Menu {
            title: qsTr("Go to...")
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
            title: qsTr("Settings...")
            MenuItem {
                text: qsTr("&Set host")
                onTriggered: hostSettings.open()
            }
        }
    }

    toolBar: ToolBar {
        style: ToolBarStyle {
            background: Rectangle {
                color: Globals.appBackground
            }
        }

        RowLayout {
            anchors.fill: parent
            ToolButton {
                id: backButton

                style: AppButtonStyle {
                    pressed: backButton.pressed
                }

                iconSource: "qrc:/images/ui/button-back.png"
                onClicked: stackView.pop()
            }

            Text {
                Layout.fillWidth: true

                text: "TOURNAMENTS"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 32
                color: Globals.textColor
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
