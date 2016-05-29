import QtQuick 2.0

import "../Globals.js" as Globals
import "../"

Rectangle {
    id: button
    width: parent.width
    height: Globals.defaultElementHeight

    property alias title: title.text
    signal clicked();

    MainText {
        id: title

        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 15
        anchors.left: parent.left
    }

    Image {
        id: arrow
        anchors.rightMargin: 15
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        source: "qrc:/images/icons-general-ui/play120.png"
    }

    MouseArea {
        id: buttonArea
        anchors.fill: parent

        onClicked: {
            button.clicked()
        }
    }

    Separator {
        anchors.bottom: parent.bottom
    }

    states: [
        State {
            name: "default"
            when: !buttonArea.pressed
            PropertyChanges {
                target: button;
                color: Globals.inactiveCellBackground
            }
        },
        State {
            name: "clicked"
            when: buttonArea.pressed
            PropertyChanges {
                target: button
                color: Globals.activeCellBackground
            }
        }
    ]
}
