import QtQuick 2.7
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.5

import "../Styles/Text"
import "../Styles/Buttons"
import "../Globals.js" as Globals

Rectangle {
    id: tournamentView
    property int headerHeight
    property bool expanded: false

    height: headerHeight
    clip: true

    anchors.leftMargin: Globals.normalMargin
    anchors.rightMargin: Globals.normalMargin

    states: State {
        name: "expanded"
        when: tournamentView.expanded
        PropertyChanges {
            target: tournamentView
            height: headerRow.height + bodyView.contentHeight
        }
    }

    Behavior on height
    {
        NumberAnimation {
            duration: 300
            easing.type: Easing.InOutQuad
        }
    }

    TournamentHeader {
        id: headerRow

        height: headerHeight
        anchors.top: tournamentView.top
        anchors.left: tournamentView.left
        anchors.right: tournamentView.right
    }

    TournamentBody {
        id: bodyView

        anchors.left: tournamentView.left
        anchors.right: tournamentView.right
        anchors.bottom: tournamentView.bottom
        anchors.top: headerRow.bottom
    }
}
