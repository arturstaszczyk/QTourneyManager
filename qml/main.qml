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
        anchors.fill: parent
        color: Globals.appBackground

        Keys.onReleased: {
            if (event.key === Qt.Key_Back || event.key === Qt.Key_Escape) {
                stackView.back(event);
            }
        }

        MainScreen {
            anchors.fill: parent
        }

//        property variant initialDate
//        Component.onCompleted: {
//            root.initialDate = new Date();
//            gameContext.restart()
//        }


//        Timer {
//            id: timer

//            interval: 1000.0 / 30.0
//            repeat: true
//            running: true
//            onTriggered: {
//                var now = new Date()
//                var diff = (now.getTime() - root.initialDate.getTime())
//                gameContext.tick( diff )
//                root.initialDate = now;
//            }
//        }

    }
}
