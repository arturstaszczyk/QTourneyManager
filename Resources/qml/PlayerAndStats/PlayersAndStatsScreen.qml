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

            StatsView {
                Layout.fillWidth: true
            }

            PlayersListView {
                Layout.fillWidth: true
            }
        }
    }
}
