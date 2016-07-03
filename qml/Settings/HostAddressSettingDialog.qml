import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.2

Dialog {
    id: hostSettings
    width: 320
    height: 80

    onAccepted: hostAddressController.onHostAddressChanged(hostAddress.text,
                                                           hostAddress.acceptableInput)

    Item {
        anchors.fill: parent

        ColumnLayout {
            spacing: 5

            Text {
                text: "Enter host address:"
                Layout.fillWidth: true
            }

            TextField {
                id:hostAddress

                validator: RegExpValidator {
                    regExp: /^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$/
                }

                placeholderText: "192.168.0.1"
                text: hostAddressModel.address

                style: TextFieldStyle {
                    textColor: "black"
                    background: Rectangle {
                        radius: 2
                        implicitWidth: 164
                        implicitHeight: 24
                        border.color: "#333"
                        border.width: 1
                    }
                }
            }
        }
    }
}
