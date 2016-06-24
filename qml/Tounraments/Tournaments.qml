import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    anchors.fill: parent

    ScrollView {
        anchors.fill: parent

        ListView {
            anchors.fill: parent
            model: tournamentsListModel.tournaments
            delegate: Button {
                width: parent.width
                height: 40
                text: modelData

                onClicked: tournamentsListController.onTournamentSelected(modelData)
            }
        }
    }

}
