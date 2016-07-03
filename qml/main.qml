import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import "Globals.js" as Globals

import "Timer"
import "Settings"
import "Tounraments"
import "Styles/Buttons"

ApplicationWindow {
    visible: true
    width: 640
    height: 960
    id: app
    property bool isCppAvailable: typeof _cpp !== "undefined"
    property QtObject _hostAddress: app.isCppAvailable ? hostAddressModel : mock.mockHostAddressModel
    property QtObject _timer: app.isCppAvailable ? timerModel : mock.mockTimerModel

    MockModels{
        id: mock
    }

    Component {
        id: tournaments
        Tournaments {}
    }

    Component{
        id: timer
        Timer {}
    }

    HostAddressSettingDialog {
        id: hostSettings
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

            Component.onCompleted: {
                navigationBarController.push("main")
            }

            Rectangle {
                id: root
                color: "transparent"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 50
                    spacing: 0

                    Button {
                        id: timerButton
                        Layout.fillWidth: true
                        text: "Show timer"

                        onClicked: {
                            stackView.push(timer)
                            navigationBarController.push("timer")
                        }

                        style: SystemButtonStyle {
                            buttonText: timerButton.text
                        }
                    }

                    Button {
                        id: tournamentButton
                        Layout.fillWidth: true
                        text: "Show tournaments"
                        onClicked: {
                            stackView.push(tournaments)
                            navigationBarController.push("tournaments")
                        }

                        style: SystemButtonStyle {
                            buttonText: tournamentButton.text
                        }
                    }

                    Button {
                        id: hostButton

                        Layout.fillWidth: true
                        text: "Set host address"
                        onClicked: hostSettings.open()

                        style: SystemButtonStyle {
                            buttonText: hostButton.text
                        }
                    }
                }
            }
        }
    }
}
