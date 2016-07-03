import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.2

import "../Styles"
import "../Styles/Buttons"
import "../Styles/Text"
import "../Globals.js" as Globals

Item {
    signal requestClose

    RoundedPage {
        id: page

        ColumnLayout {
            spacing: 15
            width: page.width

            Item {
                height: 50
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: label.implicitHeight

                MainText {
                    id: label

                    level: 3
                    anchors.fill: parent
                    anchors.leftMargin: Globals.normalMargin

                    color: Globals.textColorDark
                    text: "Enter host address:"
                }
            }

            Item {
                Layout.preferredWidth: parent.width / 1.5
                Layout.preferredHeight: hostAddress.implicitHeight

                TextField {
                    id:hostAddress
                    anchors.fill: parent
                    anchors.leftMargin: Globals.normalMargin

                    validator: RegExpValidator {
                        regExp: /^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$/
                    }

                    placeholderText: "192.168.0.1"
                    text: hostAddressModel.address

                    style: TextFieldStyle {
                        textColor: "black"
                        font.pointSize: 22
                        font.family: "Verdana"
                    }
                }
            }

            Item {
                height: 50
            }

            Button {
                Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter

                id: okButton
                text: "OK"

                style: SystemButtonStyle {
                    buttonText: okButton.text
                }

                onClicked: {
                    hostAddressController.onHostAddressChanged(hostAddress.text,
                                                               hostAddress.acceptableInput)
                    requestClose()
                }
            }
        }
    }
}
