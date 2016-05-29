import QtQuick 2.0

Rectangle {

    anchors.fill: parent

    MainControlButtons_h {
        id: controlButtons
        anchors.right: parent.right
        width: parent.height / 3.0;
        height: parent.height
    }

    MainTimer {
        id: timerView
        anchors.left: parent.left
        anchors.right: controlButtons.left
        height: parent.height
    }
}
