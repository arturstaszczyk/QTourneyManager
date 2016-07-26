import QtQuick 2.7

import "../Globals.js" as Globals

Item {

    property alias contentHeight: roundsList.contentHeight

    ListView {
        id: roundsList
        anchors.fill: parent

        model: modelData.rounds
        delegate: RoundRow {
            width: parent.width
            height: Globals.cellHeight
        }
    }
}
