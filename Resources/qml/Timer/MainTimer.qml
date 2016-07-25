import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../"
import "../Styles"
import "../Styles/Text"
import "../Globals.js" as Globals

ColumnLayout {
    id: timerView

    Item {
        Layout.fillWidth: true
        Layout.preferredHeight: Globals.normalMargin
    }

    MainText {
        Layout.fillWidth: true

        level: 3
        color: Globals.textColorDark
        text: timerModel.running ? timerModel.paused ? qsTr("paused") : qsTr("running") : qsTr("waiting...")

        horizontalAlignment: Text.AlignHCenter
    }

    Item {
        Layout.fillWidth: true
        Layout.preferredHeight: Globals.normalMargin
    }

    ListView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        boundsBehavior: Flickable.StopAtBounds

        delegate: RoundView {
            width: parent.width
            height: 50
        }

        model: timerModel.rounds
    }
}
