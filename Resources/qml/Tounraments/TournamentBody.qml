import QtQuick 2.7

import "../Globals.js" as Globals
import "../Timer"

Rectangle {

    property alias contentHeight: roundsList.contentHeight

    //color: "lightgreen"

    border.width: 1
    border.color: "black"

    radius: Globals.rectangleRadius

    ListView {
        id: roundsList
        anchors.fill: parent

        model: modelData.rounds
        delegate: RoundView {
            width: parent.width
            height: Globals.cellHeight
        }
    }
}
