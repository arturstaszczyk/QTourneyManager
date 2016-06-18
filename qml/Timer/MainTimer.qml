import QtQuick 2.0
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
                    text: "$" + timerModel.smallBlind
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
                    text: "$" + timerModel.bigBlind
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
                text: timerModel.timeString

                font.family: "Consolas"
                font.pointSize: 60
            }
        }
    }
}
