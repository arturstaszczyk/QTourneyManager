import QtQuick 2.7
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4

import "../Styles/Text"
import "../Globals.js" as Globals

ColumnLayout {

    property alias text: adminPassfordField.text

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
        text: "Admin password"
    }

    TextField {
        id: adminPassfordField
        Layout.fillWidth: true
        Layout.preferredHeight: adminPassfordField.implicitHeight

        echoMode: TextInput.Password

        text: settingsModel.adminPassword

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
