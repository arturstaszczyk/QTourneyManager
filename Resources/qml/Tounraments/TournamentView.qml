import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.2

import "../Styles/Text"
import "../Styles/Buttons"
import "../Globals.js" as Globals

Item {
    id: tournamentView

    RowLayout {
        spacing: 20
        anchors.fill: tournamentView
        anchors.leftMargin: Globals.normalMargin
        anchors.rightMargin: Globals.normalMargin

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height
            Layout.alignment: Qt.AlignLeft | Qt.AlignHCenter

            SupportText {
                color: Globals.textColorDark
                anchors.verticalCenter: parent.verticalCenter

                text: modelData
            }
        }

        Button {
            Layout.preferredWidth: tournamentView.height - 10
            Layout.preferredHeight: tournamentView.height - 10

            iconSource: "../../images/ui/button-question-small.png"

            style: RoundButtonStyle {
                backgroundColor: "gray"
            }
        }

        Button {
            Layout.preferredWidth: tournamentView.height - 10
            Layout.preferredHeight: tournamentView.height - 10

            iconSource: "../../images/ui/button-play-small.png"

            style: RoundButtonStyle {
                backgroundColor: "gray"
            }

            onClicked: {
                tournamentsListController.onPlayClicked(modelData)
                navigationBarController.requestTimerScreen();
            }
        }
    }
}
