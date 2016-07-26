import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../Styles"
import "../Styles/Text"
import "../Globals.js" as Globals

ColumnLayout {

    Item {
        Layout.fillWidth: true
        Layout.preferredHeight: Globals.normalMargin
    }

    MainText {
        Layout.fillWidth: true

        level: 3
        color: Globals.textColorDark
        horizontalAlignment: Text.AlignHCenter

        text: "Players"
    }

    Item {
        Layout.fillWidth: true
        Layout.preferredHeight: Globals.normalMargin
    }

    ListView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        boundsBehavior: Flickable.StopAtBounds

        model: playersModel.players

        delegate: PlayerView {
            width: parent.width
            height: Globals.cellHeight
        }
    }
}
