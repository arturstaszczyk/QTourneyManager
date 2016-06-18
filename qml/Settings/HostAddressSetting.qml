import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Item {

    width: 320
    height: 80

    property alias address: hostAddress.text
    property alias valid: hostAddress.acceptableInput

    Column {

        spacing: 5
        Text {
            text: "Enter host address:"
            width: parent.width
        }

        TextField {
            id:hostAddress

            validator: RegExpValidator {
                regExp: /^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$/
            }

            placeholderText: "192.168.0.1"
            text: addressModel.address

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
