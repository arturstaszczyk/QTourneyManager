import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../"
import "../Styles"
import "../Globals.js" as Globals

Rectangle {
    id: timerView
    color: "transparent"

    ListView {
        anchors.fill: parent
        anchors.topMargin: 50
        boundsBehavior: Flickable.StopAtBounds

        delegate: RoundView {
            width: parent.width
            height: 50
        }

        model: timerModel.rounds
    }
}
