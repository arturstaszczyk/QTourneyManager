import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Dialog {

    modality: Qt.WindowModal
    title: "Hello"

    standardButtons: StandardButton.Save | StandardButton.Cancel

    Rectangle {
        height: 80
        anchors.left: parent.left
        anchors.right: parent.right
        color: "green"
    }
}
