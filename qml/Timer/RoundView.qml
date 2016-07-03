import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../Styles/Text"
import "../Globals.js" as Globals

Rectangle {
    id: roundView
    property bool isActive: (index === timerModel.activeRound) && timerModel.running

    color: isActive ? "#8fd9d0" : "transparent"

    RowLayout {
        anchors.fill: parent
        anchors.margins: 5
        anchors.leftMargin: 20
        anchors.rightMargin: 20

        SupportText {
            Layout.alignment: Layout.Left
            text: "BLINDS: $" + modelData.smallBlind + " / $" + modelData.bigBlind
            color: roundView.isActive ?  Globals.textColorLight : Globals.textColorDark
        }

        SupportText {
            Layout.alignment: Layout.Right
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight

            text: roundView.isActive ? timerModel.activeRoundRemainingTime : modelData.roundTimeString
        }
    }
}
