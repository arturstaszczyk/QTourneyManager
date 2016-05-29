import QtQuick 2.0
import pokermanager.types 1.0
import "../Globals.js" as Globals

Item{
    property RoundDef activeRound: gameContext.activeRound

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
                    text: "$" + activeRound.smallBlind
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
                    text: "$" + activeRound.bigBlind
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
                    if(!gameContext.activeRound.isValid)
                        return "--:--";

                    var minutesLeft = gameContext.activeRoundMinutesLeft;
                    var secondsLeft = gameContext.activeRoundSecondsLeft;
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
