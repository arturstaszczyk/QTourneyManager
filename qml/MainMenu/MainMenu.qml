import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: menu
    color: "transparent"

    signal changeUrl(string url, string name);

    ListModel {
        id: buttonTitles
        ListElement {
            name: "Edit blinds"
            url: "BlindsEditor/BlindsListEditor.qml"
        }
        ListElement {
            name: "Edit players"
            url: "BlindsEditor/BlindsListEditor.qml"
        }
        ListElement {
            name: "Edit prize"
            url: "BlindsEditor/BlindsListEditor.qml"
        }
        ListElement {
            name: "Edit chips"
            url: "BlindsEditor/BlindsListEditor.qml"
        }
    }

    ListView {
        id: mainMenu
        anchors.fill: parent

        clip: true;
        model: buttonTitles
        delegate: MainMenuButton{
            title: name
            onClicked: {
                menu.changeUrl(url, name);
            }
        }
    }
}
