﻿import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.2

import "../Styles/Text"
import "../Styles/Buttons"
import "../Globals.js" as Globals

Rectangle {
    id: tournamentView
    property int headerHeight

    height: headerHeight

    color: "red"

    Behavior on height
    {
        NumberAnimation {
            duration: 500
            easing.type: Easing.InOutQuad
        }
    }

    RowLayout {
        id: headerRow

        height: headerHeight
        anchors.top: tournamentView.top
        anchors.left: tournamentView.left
        anchors.right: tournamentView.right
        anchors.leftMargin: Globals.normalMargin
        anchors.rightMargin: Globals.normalMargin

        spacing: 20

        SupportText {
            Layout.fillWidth: true
            Layout.fillHeight: true

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            color: Globals.textColorDark
            text: modelData
        }

        Button {
            Layout.preferredWidth: headerRow.height - 10
            Layout.preferredHeight: headerRow.height - 10

            iconSource: "../../images/ui/button-question-small.png"

            style: RoundButtonStyle {
                backgroundColor: "gray"
            }

            onClicked: {
                tournamentView.height += 30
            }
        }

        Button {
            Layout.preferredWidth: headerRow.height - 10
            Layout.preferredHeight: headerRow.height - 10

            iconSource: "../../images/ui/button-play-small.png"

            style: RoundButtonStyle {
                backgroundColor: "gray"
            }

            onClicked: {
                tournamentsListController.onPlayClicked(modelData)
                navigationBarController.requestTimerScreen();
            }
        }
    }

    Rectangle {

        anchors.left: tournamentView.left
        anchors.right: tournamentView.right
        anchors.top: headerRow.bottom
        anchors.bottom: tournamentView.bottom
    }
}
