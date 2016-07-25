import QtQuick 2.0
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.2

import "../Styles/Text"
import "../Styles/Buttons"
import "../Globals.js" as Globals

Rectangle {
    id: playerView
    color: modelData.eliminated ? Globals.appBackground : "transparent"

    RowLayout {
        anchors.fill: parent

        MainText {

            Layout.fillHeight: true
            Layout.preferredWidth: parent.width / 3
            color: modelData.eliminated ? Globals.supportTextColor : Globals.textColorDark
            level: 3

            text: modelData.nick

            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        MainText {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width / 3
            color: modelData.eliminated ? Globals.supportTextColor : Globals.textColorDark
            level: 3

            text: "Rebuys: " + modelData.rebuyCount
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        Button {
            Layout.preferredWidth: playerView.height - 10
            Layout.preferredHeight: playerView.height - 10

            iconSource: "../../images/ui/button-question-small.png"

            style: RoundButtonStyle {
                backgroundColor: "gray"
            }

            onClicked: playersAndStatsController.eliminate(modelData.nick)
        }

        Button {
            Layout.preferredWidth: playerView.height - 10
            Layout.preferredHeight: playerView.height - 10

            iconSource: "../../images/ui/button-play-small.png"

            style: RoundButtonStyle {
                backgroundColor: "gray"
            }

            onClicked: playersAndStatsController.rebuy(modelData.nick)
        }
    }
}
