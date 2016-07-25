import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../Styles"
import "../Styles/Text"
import "../Globals.js" as Globals

Item {
    RoundedPage {
        id: timerScreen

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: Globals.normalMargin

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: Globals.normalMargin
            }

            StatsView {
                Layout.fillWidth: true
            }

            ListView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                boundsBehavior: Flickable.StopAtBounds

                model: playersModel.players

                delegate: PlayerView {
                    width: parent.width
                    height: 60
                }
            }
        }
    }
}
