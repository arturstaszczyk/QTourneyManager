import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "../"
import "../Styles"

Item{
    id: tournamentsList
    signal showTimer;

    RoundedPage {

        ListView {

            anchors.fill: parent
            anchors.topMargin: 50
            boundsBehavior: Flickable.StopAtBounds

            model: tournamentsListModel.tournaments

            delegate: TournamentView {
                width: parent.width
                height: 60

                onShowTimer: {
                    tournamentsList.showTimer()
                }
            }
        }
    }
}
