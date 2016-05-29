import QtQuick 2.5
import QtQuick.Window 2.2
import pokermanager.types 1.0

import "Globals.js" as Globals
import "MainMenu"
import "MainScreen"

Window {
    visible: true
    width: 640
    height: 960

    Rectangle {
        id: root
        objectName: "root"
        focus: true
        anchors.fill: parent
        color: Globals.appBackground

        // todo: model
        property variant initialDate

        Component.onCompleted: {
            root.initialDate = new Date();
            gameContext.restart()
        }

        Keys.onReleased: {
            if (event.key === Qt.Key_Back || event.key === Qt.Key_Escape) {
                stackView.back(event);
            }
        }

        Timer {
            id: timer

            interval: 1000.0 / 30.0
            repeat: true
            running: true
            onTriggered: {
                var now = new Date()
                var diff = (now.getTime() - root.initialDate.getTime())
                gameContext.tick( diff )
                root.initialDate = now;
            }
        }

        Loader {
            id: loader
            anchors.fill: parent
        }

        states: [
            State {
                name: "default"
                when: root.width < root.height
                PropertyChanges {
                    target: loader;
                    source: "MainScreen/MainScreen_v.qml"
                }
            },
            State {
                name: "horizontal"
                when: root.width >= root.height
                PropertyChanges {
                    target: loader
                    source: "MainScreen/MainScreen_h.qml"
                }
            }
        ]
    }
}
