import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3

import "Globals.js" as Globals

import "Timer"
import "Settings"
import "Tounraments"
import "Styles/Buttons"

ApplicationWindow {
    id: app
    visible: true
    width: 640
    height: 960

//    property bool isCppAvailable: typeof _cpp !== "undefined"
//    property QtObject _hostAddress: app.isCppAvailable ? hostAddressModel : mock.mockHostAddressModel
//    property QtObject _timer: app.isCppAvailable ? timerModel : mock.mockTimerModel

//    MockModels{
//        id: mock
//    }

    Connections {
        target: navigationBarModel
        onRequestedScreenChanged: {
            if(navigationBarModel.requestedScreen == "timer")
            {
                stackView.push(timer)
                navigationBarController.push("timer")
            }
        }
    }


    Component {
        id: tournaments
        Tournaments {}
    }

    Component{
        id: timer
        Timer {}
    }

    Component {
        id: hostSettings
        HostAddressSetting {
            onRequestClose: {
                stackView.pop()
                navigationBarController.pop()
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

            focus: true

            Keys.onReleased: {
                if(event.key === Qt.Key_Back)
                {
                    if(!navigationBarModel.isRoot)
                    {
                        stackView.pop()
                        navigationBarController.pop()
                    }
                    event.accepted = true
                }
            }

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
                        onClicked: {
                            stackView.push(hostSettings)
                            navigationBarController.push("settings/host address")
                        }

                        style: SystemButtonStyle {
                            buttonText: hostButton.text
                        }
                    }
                }
            }
        }
    }
}
