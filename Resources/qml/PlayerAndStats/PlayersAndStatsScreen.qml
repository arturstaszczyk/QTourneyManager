import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../Styles"
import "../Globals.js" as Globals

Item {
    RoundedPage {
        id: timerScreen

        ListView {
            anchors.fill: parent
            anchors.topMargin: 50
            boundsBehavior: Flickable.StopAtBounds

            model: playersAndStatsModel.players

            delegate: PlayerView {
                width: parent.width
                height: 60
            }
        }
    }
}
