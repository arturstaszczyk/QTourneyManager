import QtQuick 2.0
import QtQuick.Layouts 1.2

import "../Styles/Text"
import "../Globals.js" as Globals

Item {
    id: playerView

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Globals.normalMargin
        anchors.rightMargin: Globals.normalMargin

        MainText {

            Layout.fillHeight: true
            Layout.preferredWidth: parent.width / 3
            color: Globals.textColorDark
            level: 3

            text: modelData.nick

            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        MainText {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width / 3
            color: Globals.textColorDark
            level: 3

            text: "Rebuys: " + modelData.rebuyCount
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
    }
}
