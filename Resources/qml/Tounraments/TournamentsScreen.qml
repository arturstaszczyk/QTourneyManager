import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "../"
import "../Styles"
import "../Globals.js" as Globals

Item{
    id: tournamentsList
    RoundedPage {

        ColumnLayout
        {
            anchors.fill: parent

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: Globals.normalMargin
            }

            ListView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                boundsBehavior: Flickable.StopAtBounds

                model: tournamentsListModel.tournaments

                delegate: TournamentView {
                    width: parent.width
                    headerHeight: 60
                }
            }
        }
    }
}
