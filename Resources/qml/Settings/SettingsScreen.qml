import QtQuick 2.7
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.5

import "../Styles"
import "../Styles/Buttons"
import "../Globals.js" as Globals

Item {

    RoundedPage {
        id: page

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: Globals.normalMargin

            HostAddress {
                id: hostAddress

                Layout.fillWidth: true
            }

            Button {
                Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter

                id: okButton
                text: "OK"

                style: SystemButtonStyle {
                    buttonText: okButton.text
                }

                onClicked: {
                    settingsController.onHostAddressChanged(hostAddress.text,
                                                               hostAddress.acceptableInput)
                    navigationBarController.requestPop()
                }
            }
        }
    }
}
