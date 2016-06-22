import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0

import "../"
import "../Globals.js" as Globals

Rectangle{
    id: cell
    clip: true

    height: extended ? 2 * Globals.defaultElementHeight : Globals.defaultElementHeight
    color: "transparent"

    property bool extended: false;
    property alias isBreak: breakCheckbox.selected

    signal deleteMe()
    signal changeMe(int small, int big, int time)

    property string smallBlindValue;
    property string timeValue;

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(!cell.extended)
            {
                cell.extended = true
                smallBlindValue = sb;
                timeValue = time;
            }
        }
    }

    Column{
        width: parent.width
        height: 2 * Globals.defaultElementHeight

        Loader {
            id: cellLoader
            sourceComponent: extended ? editCell : viewCell
            width: parent.width
            height: Globals.defaultElementHeight
        }

        RowLayout {
            width: parent.width
            height: Globals.defaultElementHeight
            spacing:0

            Checkbox {
                id: breakCheckbox
                Layout.preferredWidth: parent.width/2
                height: Globals.defaultElementHeight

                Layout.alignment: Qt.AlignCenter
                anchors.verticalCenter: parent.verticalCenter
                text: "Break?"
                textColor: Globals.secondaryTextColor
            }

            Button {
                Layout.preferredWidth: parent.width/4
                Layout.preferredHeight: Globals.defaultElementHeight

                text: "Delete"
                textColor: Globals.secondaryTextColor

                onClicked: cell.deleteMe()
            }

            Button {
                Layout.preferredWidth: parent.width/4
                Layout.preferredHeight: Globals.defaultElementHeight

                text: "OK"
                textColor: Globals.secondaryTextColor
                onClicked: {
                    cell.extended = false;
                    if(timeValue === "" || timeValue === "0")
                        timeValue = Globals.defaultRoundTime.toString()
                    cell.changeMe(smallBlindValue, smallBlindValue * 2, timeValue)
                }
            }
        }

    }

    Component {
        id: viewCell

        RowLayout {
            MainText {
                Layout.preferredWidth: parent.width/2
                Layout.alignment: Qt.AlignCenter

                text: isBreak ? '<b>BREAK</b>' : '<b>Blinds:</b> $' + sb + "/$" + bb
                horizontalAlignment: Text.AlignHCenter;
            }

            MainText {
                Layout.preferredWidth: parent.width/2
                Layout.alignment: Qt.AlignCenter
                text: '<b>Time: </b>' + time
                horizontalAlignment: Text.AlignHCenter;
            }
        }
    }

    Component {
        id: editCell

        RowLayout {
            MainText {
                text: qsTr("Small blind")
                Layout.alignment: Qt.AlignCenter
            }
            TextField {
                Layout.minimumWidth: 70
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignCenter
                style: textFieldStyle

                onFocusChanged: smallBlindValue = text

            }
            MainText {
                text: qsTr("Time")
                Layout.alignment: Qt.AlignCenter
            }
            TextField {
                Layout.minimumWidth: 70
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignCenter
                style: textFieldStyle

                onFocusChanged:
                {
                    timeValue = text
                }
            }
        }
    }

    Component {
        id: textFieldStyle

        TextFieldStyle {
            textColor: "blue"
            font.pixelSize: 20
            background: Item {
                BorderImage {
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    source: "../../../images/textinput.png"
                    border.left: 8;
                    border.right: 8; border.bottom: 8
                }
            }
        }
    }

    Behavior on height{
        NumberAnimation { duration: 200; easing.type: Easing.InOutCubic }
    }

    Rectangle {
        width:parent.width
        height:3
        color: Globals.separatorColor
        anchors.bottom: parent.bottom
    }
}
