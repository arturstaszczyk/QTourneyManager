import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../Styles"

Item {
    RoundedPage {
        id: timerScreen

        ListView {
            anchors.fill: parent
            anchors.topMargin: 50
            boundsBehavior: Flickable.StopAtBounds

            model: playersAndStatsModel.players
            delegate: Rectangle {
                color: "red"
                width: 100
                height: 60
                border {
                    width: 1
                    color: "black"
                }
                Text {
                    text: modelData.nick
                }
            }
        }
    }
}
