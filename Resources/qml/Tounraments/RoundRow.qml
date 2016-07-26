import QtQuick 2.7

import "../Styles/Text"
import "../Globals.js" as Globals

Item {
    SupportText {
        anchors.fill: parent
        anchors.margins: Globals.normalMargin

        //text: modelData.smallBlind + "/" + modelData.bigBlind + "  - " + modelData.

        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
    }
}
