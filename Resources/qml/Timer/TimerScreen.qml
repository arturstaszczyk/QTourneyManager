import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.5

import "../Styles"
import "../Styles/Buttons"
import "../Globals.js" as Globals

Item {
    RoundedPage {
        id: timerScreen

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            MainTimer {
                id: timerView

                Layout.fillWidth: true
                Layout.preferredHeight: timerScreen.height / 4.0 * 3
            }

            MainControlButtons {
                id: controlButtons

                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 4.0
            }

            Button {
                id: showPlayersAndStatsButton
                Layout.fillWidth: true
                text: "Show players & stats"

                onClicked: navigationBarController.requestPlayerAndStatsScreen()
                style: SystemButtonStyle {
                    buttonText: showPlayersAndStatsButton.text
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: Globals.normalMargin
            }

        }
    }
}
