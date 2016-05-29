import QtQuick 2.0

Rectangle {

    anchors.fill: parent

    MainTimer {
        id: timerView
        anchors.top: parent.top
        anchors.bottom: controlButtons.top
        width: parent.width;
        height: parent.height * 3.0 / 5.0
    }

    MainControlButtons_v {
        id: controlButtons
        anchors.bottom: parent.bottom
        width: parent.width;
        height: (parent.width / 3.0)
    }
}
