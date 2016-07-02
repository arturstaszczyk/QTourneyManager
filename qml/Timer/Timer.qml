import QtQuick 2.7
import QtQuick.Layouts 1.3

Item {
    Rectangle {
        id: timerScreen
        color: "white"
        radius: 20
        clip: true

        anchors {
            fill: parent
            topMargin: 50
            leftMargin: 50
            rightMargin: 50
        }

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            MainTimer {
                id: timerView

                Layout.fillWidth: true
                Layout.preferredHeight: timerScreen.height / 4.0 * 3
            }

            MainControlButtons {
                id: controlButtons

                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 4.0
            }

        }
    }
}
