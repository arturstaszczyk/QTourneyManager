import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

import "Styles/Buttons"
import "Styles/Text"

Item {
    id: navigationBar

    height: 80

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10

        Button {
            id: backButton
            style: TransparentButtonStyle {}

            visible: !navigationBarModel.isRoot
            iconSource: "../images/ui/button-back.png"

            onClicked: navigationBarController.requestPop()
        }

        MainText {
            level: 3
            Layout.fillWidth: true
            text: navigationBarModel.title
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
