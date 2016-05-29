import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0

import "../"
import "../Globals.js" as Globals

Rectangle {
    color: "transparent"

    ListModel {
        id: myModel

        ListElement {
            sb: "1"
            bb: "2"
            time: "20"
        }
    }

    ListView {
        id: blindsList
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: contentHeight

        clip: true
        model: myModel
        delegate: BlindsListCell {
            width: parent.width

            onDeleteMe: {
                myModel.remove(index)
            }

            onChangeMe: {
                myModel.set(index, {
                                "sb": small.toString(),
                                "bb": big.toString(),
                                "time": time.toString()})
            }
        }
    }

    AddBlindsButton {
        width: parent.width;
        height: Globals.defaultElementHeight
        anchors.top: blindsList.bottom

        onClicked: {
            myModel.append({"sb": "1", "bb": "2", "time": "20"})
        }
    }
}
