import QtQuick 2.7
import "../../Globals.js" as Globals

Text {

    property int level: 1

    color: Globals.textColorLight

    font.family: "Verdana"
    font.pointSize: level == 1 ? 60 : level == 2 ? 48 : 32
    text: ""
}
