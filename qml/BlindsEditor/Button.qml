import QtQuick 2.0
import "../Globals.js" as Globals

Rectangle {
    id: button
    border.width: 1
    border.color: Globals.separatorColor

    property alias text: title.text
    property alias textColor: title.color

    signal clicked();

    MainText {
        id: title

        anchors.centerIn: parent
    }

    MouseArea {
        id: buttonArea
        anchors.fill: parent

        onClicked: {
            button.clicked()
        }
    }

    states: [
        State {
            name: "default"
            when: !buttonArea.pressed
            PropertyChanges {
                target: button;
                color: Globals.debugColor1
            }
        },
        State {
            name: "clicked"
            when: buttonArea.pressed
            PropertyChanges {
                target: button
                color: Globals.debugColor2
            }
        }
    ]
}
