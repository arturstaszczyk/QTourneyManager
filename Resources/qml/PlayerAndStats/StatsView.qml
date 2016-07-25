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
            text: qsTr("Total chips on the table")
        }

        SupportText {
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
            text: statsModel.totalChips
        }
    }

    RowLayout {
        Layout.fillWidth: true

        SupportText {
            Layout.fillWidth: true
            text: qsTr("Players in game")
        }

        SupportText {
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
            text: statsModel.playersInGame
        }
    }

    RowLayout {
        Layout.fillWidth: true

        SupportText {
            Layout.fillWidth: true
            text: qsTr("Av. chips per player")
        }

        SupportText {
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
            text: statsModel.averageChipsCount
        }
    }

    RowLayout {
        Layout.fillWidth: true

        SupportText {
            Layout.fillWidth: true
            text: qsTr("Buyin")
        }

        SupportText {
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
            text: statsModel.buyinChips + "/" + qsTr("PLN") + statsModel.buyinCash
        }
    }

}
