import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../"
import "../Styles"
import "../Globals.js" as Globals

Rectangle {
    id: timerView
    color: Globals.secondaryColor

    border.color: "red"
    border.width: 5

    ColumnLayout {
        anchors.fill: parent
        spacing: 1

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 5.0

            RowLayout {
                anchors.fill: parent
                spacing: 1

                Rectangle {
                    Layout.preferredWidth: parent.width / 2.0
                    Layout.preferredHeight: parent.height

                    color: Globals.appBackground

                    MainText {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "Small blind\n$" + _timer.smallBlind
                        font.family: "Consolas"
                        font.pointSize: 40
                    }
                }

                Rectangle {
                    Layout.preferredWidth: parent.width / 2.0
                    Layout.preferredHeight: parent.height

                    color: Globals.appBackground
                    border.width: 1
                    border.color: Globals.secondaryColor

                    MainText {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "$" + _timer.bigBlind
                        font.family: "Consolas"
                        font.pointSize: 40
                    }
                }
            }
        }

        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height / 5.0 * 4.0

            color: Globals.appBackground

            MainText {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: _timer.timeString
            }
        }
    }
}
