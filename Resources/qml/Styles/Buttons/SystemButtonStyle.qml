import QtQuick 2.7
import QtQuick.Controls.Styles 1.4

import "../../Globals.js" as Globals
import "../Text"


ButtonStyle {
    property string buttonText
    label: Component {
        SupportText {
            anchors.centerIn: parent
            color: Globals.textColorDark
            text: buttonText

            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }
}
