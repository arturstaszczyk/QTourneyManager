import QtQuick 2.0
import pokermanager.types 1.0
import "../Globals.js" as Globals

Item{

    Column {
        anchors.fill: parent

        Row {

            width: parent.width
            height: parent.height / 3.0

            Rectangle {
                width: parent.width / 2.0
                height: parent.height
                color: Globals.debugColor1
                border.width: 1
                border.color: Globals.separatorColor

                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "$" + mainScreenController.activeRound.blinds.smallBlind
                    font.family: "Consolas"
                    font.pointSize: 40
                }
            }

            Rectangle {
                width: parent.width / 2.0
                height: parent.height
                color: Globals.debugColor1
                border.width: 1
                border.color: Globals.separatorColor

                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "$" + mainScreenController.activeRound.blinds.bigBlind
                    font.family: "Consolas"
                    font.pointSize: 40
                }
            }
        }

        Rectangle {
            width: parent.width;
            height: parent.height * 2.0 / 3.0
            color: Globals.debugColor1
            border.width: 1
            border.color: Globals.separatorColor

            Text {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: {
                    if(!mainScreenController.activeRound.isValid)
                        return "--:--";

                    var minutesLeft = mainScreenController.activeRoundMinutesLeft;
                    var secondsLeft = mainScreenController.activeRoundSecondsLeft;
                    var minutesStr = minutesLeft < 10 ? "0" + minutesLeft.toString() : minutesLeft.toString()
                    var secondsStr = secondsLeft < 10 ? "0" + secondsLeft.toString() : secondsLeft == 60 ? "00" : secondsLeft.toString()

                    return minutesStr + ":" + secondsStr
                }

                font.family: "Consolas"
                font.pointSize: 60
            }
        }
    }
}
