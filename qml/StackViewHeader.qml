import QtQuick 2.0
import "Globals.js" as Globals

Rectangle {
    id: header
    width: parent.width
    height: Globals.defaultElementHeight
    color: Globals.activeCellBackground

    property alias text: headerText.text
    property alias backVisible: backImage.visible

    signal backClicked()

    Image {
        anchors.fill: parent
        source: "../../images/toolbar.png"
    }

    Image {
        id: backImage
        anchors.verticalCenter: parent.verticalCenter
        source: "../../images/navigation_previous_item.png"

        opacity: buttonMouseArea.pressed ? 0.5 : 1

        MouseArea {
            id: buttonMouseArea
            anchors.fill: parent

            onClicked: {
                header.backClicked()
            }
        }
    }

    MainText {
        id: headerText
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 10
        text: ""

        states: [
            State {
                name: "backInvisible"
                when: !backImage.visible
                PropertyChanges {
                    target: headerText
                    anchors.left: parent.left
                }
            },

            State {
                name: "backVisible"
                when: backImage.visible
                PropertyChanges {
                    target: headerText
                    anchors.left: backImage.right
                }
            }
        ]
    }
}
