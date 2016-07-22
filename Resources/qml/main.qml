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
        HostAddressSetting {}
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
            objectName: "MainStackView"
            Layout.fillWidth: true
            Layout.fillHeight: true
            initialItem: root

            focus: true

            Keys.onReleased: {
                if(event.key === Qt.Key_Back)
                {
                    if(!navigationBarModel.isRoot)
                    {
                        navigationBarController.requestPop()
                    }
                    event.accepted = true
                }
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

                        onClicked: navigationBarController.requestTimerScreen()
                        style: SystemButtonStyle {
                            buttonText: timerButton.text
                        }
                    }

                    Button {
                        id: playerAndStatsButton
                        Layout.fillWidth: true
                        text: "Players & Stats"

                        onClicked: navigationBarController.requestPlayerAndStatsScreen()
                        style: SystemButtonStyle {
                            buttonText: tournamentButton.text
                        }
                    }

                    Button {
                        id: tournamentButton
                        Layout.fillWidth: true
                        text: "Show tournaments"

                        onClicked: navigationBarController.requestTournamentScreen()
                        style: SystemButtonStyle {
                            buttonText: tournamentButton.text
                        }
                    }
                    Button {
                        id: hostButton

                        Layout.fillWidth: true
                        text: "Set host address"
                        onClicked: navigationBarController.requestHostAddressScreen()

                        style: SystemButtonStyle {
                            buttonText: hostButton.text
                        }
                    }
                }
            }
        }
    }
}
