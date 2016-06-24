import QtQuick 2.0

Rectangle {

    MainTimer {
        id: timerView
        anchors.top: parent.top
        anchors.bottom: controlButtons.top
        width: parent.width;
        height: parent.height * 3.0 / 5.0
    }

    MainControlButtons {
        id: controlButtons
        anchors.bottom: parent.bottom
        width: parent.width;
        height: (parent.width / 6.0)
    }
}
