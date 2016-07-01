import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

import "Styles"

Rectangle {
    id: navigationBar

    height: 80
    border.width: 0
    border.color: "red"
    color: "transparent"

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10

        Button {
            id: backButton
            style: AppButtonStyle {
                pressed: backButton.pressed
            }

            iconSource: "../images/ui/button-back.png"
            onClicked: stackView.pop()
        }

        MainText {
            level: 3
            Layout.fillWidth: true
            text: "menu"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
