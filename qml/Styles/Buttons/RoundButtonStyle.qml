import QtQuick 2.7
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

import "../../Globals.js" as Globals

ButtonStyle {

    property color backgroundColor: Globals.roundButtonColor;

    background: Item {

        Rectangle {
            id: back
            radius: 30
            anchors.fill: parent
            color: backgroundColor

            visible: false
        }

        Image {
            id: mask
            anchors.fill: parent
            source: "../../../images/ui/mask-button-round.png"
            sourceSize: Qt.size(parent.width, parent.height)
            smooth: true
            antialiasing: true
            visible: false
        }

        OpacityMask {
            anchors.fill: parent
            source: back
            maskSource: mask
            smooth: true
            antialiasing: true
        }
    }
}
