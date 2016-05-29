import QtQuick 2.0
import QtQuick.Layouts 1.0

import "Globals.js" as Globals

Rectangle {
    id: root
    width: 100
    height: 50
    color: "transparent"

    border.color: Globals.separatorColor
    border.width: 1

    property bool selected: false

    property alias text: label.text
    property alias textColor: label.color

    RowLayout
    {
        anchors.fill: parent

        MainText {
            id: label
            Layout.alignment: Qt.AlignHCenter | Qt.AlignCenter
            text: ""
        }

        Image {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignCenter
            source: root.selected ? "../../images/check_on.png" : "../../images/check_off.png"
            opacity: 0.6
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            selected = !selected
        }
    }
}
