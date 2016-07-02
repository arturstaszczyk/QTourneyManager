﻿import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

import "../Globals.js" as Globals

ButtonStyle {

    background: Item {

        Rectangle {
            id: back
            radius: 30
            anchors.fill: parent
            color: Globals.roundButtonColor

            visible: false
        }

        Image {
            id: mask
            anchors.fill: parent
            source: "../../images/ui/mask-button-round.png"
            sourceSize: Qt.size(parent.width, parent.height)
            smooth: true
            visible: false
        }

        OpacityMask {
            anchors.fill: parent
            source: back
            maskSource: mask
        }
    }
}
