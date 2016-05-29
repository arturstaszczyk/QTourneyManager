import QtQuick 2.0

import "../"
import "../Globals.js" as Globals

Rectangle {
    id: button
    color: addBlindsArea.pressed ? Globals.activeCellBackground : Globals.inactiveCellBackground

    signal clicked()

    Image {
        source: "../../../images/plus.png"
        anchors.centerIn: parent
    }

    MouseArea {
        id: addBlindsArea
        anchors.fill: parent

        onClicked: button.clicked()
    }

    Separator {
        anchors.bottom: parent.bottom
    }
}
