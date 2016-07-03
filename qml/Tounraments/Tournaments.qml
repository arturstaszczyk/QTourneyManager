import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "../"
import "../Styles"

Item{
    Rectangle {
        color: "white"
        radius: 20
        clip: true

        anchors {
            fill: parent
            topMargin: 50
            leftMargin: 50
            rightMargin: 50
        }

        ListView {

            anchors.fill: parent
            anchors.topMargin: 50
            boundsBehavior: Flickable.StopAtBounds

            model: tournamentsListModel.tournaments

            delegate: TournamentView {
                width: parent.width
                height: 40
            }
        }
    }
}
