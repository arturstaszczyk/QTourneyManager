import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.2

import "../Styles"
import "../Styles/Buttons"
import "../Styles/Text"
import "../Globals.js" as Globals

ColumnLayout {

    property alias text: hostAddressField.text
    property alias acceptableInput: hostAddressField.acceptableInput

    Item {
        Layout.fillWidth: true
        Layout.preferredHeight: Globals.normalMargin
    }

    MainText {
        id: label

        Layout.fillWidth: true
        Layout.preferredHeight: label.implicitHeight


        level: 3
        color: Globals.textColorDark
        text: "REST service address:"
    }

    TextField {
        id: hostAddressField
        Layout.fillWidth: true
        Layout.preferredHeight: hostAddressField.implicitHeight

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

    Item {
        height: Globals.normalMargin
    }
}
