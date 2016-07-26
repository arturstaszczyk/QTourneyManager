import QtQuick 2.7
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.5

import "../Styles/Text"
import "../Styles/Buttons"
import "../Globals.js" as Globals

RowLayout {
    id: root
    spacing: 10

    SupportText {
        Layout.fillWidth: true
        Layout.fillHeight: true

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft

        color: Globals.textColorDark
        text: modelData.name
    }

    Button {
        Layout.preferredWidth: root.height - 20
        Layout.preferredHeight: root.height - 20

        iconSource: "../../images/ui/button-question-small.png"

        style: RoundButtonStyle {
            backgroundColor: "gray"
        }

        onClicked: tournamentView.expanded = !tournamentView.expanded
    }

    Button {
        Layout.preferredWidth: headerRow.height - 20
        Layout.preferredHeight: headerRow.height - 20

        iconSource: "../../images/ui/button-play-small.png"

        style: RoundButtonStyle {
            backgroundColor: "gray"
        }

        onClicked: {
            tournamentsListController.onPlayClicked(modelData.name)
            navigationBarController.requestTimerScreen();
        }
    }
}
