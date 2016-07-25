import QtQuick 2.7
import QtQuick.Layouts 1.3

import "../Styles"

Item {
    RoundedPage {
        id: timerScreen

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

//            Item {
//                Layout.fillWidth: true
//                Layout.preferredHeight: 30
//            }

            MainTimer {
                id: timerView

                Layout.fillWidth: true
                Layout.preferredHeight: timerScreen.height / 4.0 * 3
            }

            MainControlButtons {
                id: controlButtons

                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 4.0
            }

        }
    }
}
