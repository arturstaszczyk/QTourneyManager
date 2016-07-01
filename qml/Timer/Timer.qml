import QtQuick 2.7
import QtQuick.Layouts 1.3

Item {
    id: timerScreen
    anchors.fill: parent

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
