import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.2

import "../Globals.js" as Globals
import "../Styles/Text"
import "../Styles/Buttons"

Item {
    id: tournamentView

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Globals.leftMargin
        anchors.rightMargin: Globals.leftMargin

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height
            Layout.alignment: Qt.AlignLeft | Qt.AlignHCenter

            SupportText {
                color: Globals.textColorDark
                anchors.verticalCenter: parent.verticalCenter

                text: modelData
            }
        }

        Button {
            Layout.preferredWidth: tournamentView.height - 10
            Layout.preferredHeight: tournamentView.height - 10

            iconSource: "../../images/ui/button-play-small.png"

            style: RoundButtonStyle {
            }
        }
    }

//Button {
//    width: parent.width
//    height: 40
//    text: modelData

//    style: ButtonStyle {
//        background: Column{
//            Rectangle {
//                width: parent.width
//                height: 1
//                color: "black"
//            }
//            Rectangle{
//                width: parent.width
//                height: parent.height - 2
//                color: "green"
//            }

//            Rectangle {
//                width: parent.width
//                height: 1
//                color: "black"
//            }
//        }
//    }

//    onClicked: tournamentsListController.onTournamentSelected(modelData)
//}
}
