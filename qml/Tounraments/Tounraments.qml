import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    anchors.fill: parent

    ScrollView {
        anchors.fill: parent

        ListView {
            model: tournamentsListModel.tournaments
            delegate: Button {
                text: modelData
            }
        }
    }

}
