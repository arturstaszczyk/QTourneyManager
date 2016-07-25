import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../Styles/Text"
import "../Globals.js" as Globals

ColumnLayout {

    MainText {
        Layout.fillWidth: true

        level: 3
        color: Globals.textColorDark
        horizontalAlignment: Text.AlignHCenter

        text: "Stats"
    }

    RowLayout {
        Layout.fillWidth: true

        SupportText {
            Layout.fillWidth: true
            text: qsTr("Average chips count: ")
        }

        SupportText {
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
            text: playersAndStatsModel.averageChipsCount
        }
    }

}
