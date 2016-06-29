import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ".."

Rectangle {

    HeaderText {
        id: header
        width: parent.width
        height: 40
        text: "Avalilable tournaments"

        anchors.topMargin: 20
    }

    ScrollView {
        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom

            margins: 20
        }

        ListView {
            anchors.fill: parent
            model: tournamentsListModel.tournaments
            delegate: Button {
                width: parent.width
                height: 40
                text: modelData

                style: ButtonStyle {
                    background: Column{
                        Rectangle {
                            width: parent.width
                            height: 1
                            color: "black"
                        }
                        Rectangle{
                            width: parent.width
                            height: parent.height - 2
                            color: "green"
                        }

                        Rectangle {
                            width: parent.width
                            height: 1
                            color: "black"
                        }
                    }
                }

                onClicked: tournamentsListController.onTournamentSelected(modelData)
            }
        }
    }

}
