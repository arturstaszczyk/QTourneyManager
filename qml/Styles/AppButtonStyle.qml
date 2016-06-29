import QtQuick 2.0
import QtQuick.Controls.Styles 1.4

import "../Globals.js" as Globals

ButtonStyle {
    id: appButtonStyle
    property bool pressed

    background: Rectangle {
        id: buttonBackground

        states: [
            State {
                name: "normal"
                when: !appButtonStyle.pressed
                PropertyChanges { target: buttonBackground; color: Globals.buttonNormal }
            },

            State {
                name: "pressed"
                when: appButtonStyle.pressed
                PropertyChanges { target: buttonBackground; color: Globals.buttonPressed }
            }
        ]
    }
}
