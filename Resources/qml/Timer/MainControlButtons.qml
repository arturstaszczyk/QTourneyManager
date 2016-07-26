import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import "../Globals.js" as Globals
import "../Styles/Buttons"

Item {
    id: timerButtonsView

    RowLayout {
        anchors.fill: parent
        anchors.margins: Globals.normalMargin
        spacing: 0

        Item {
            Layout.preferredWidth: timerButtonsView.width / 3
            Layout.fillHeight: true

            Button {
                id: prevButton

                anchors.centerIn: parent
                width: 50
                height: 50

                style: RoundButtonStyle {}
                iconSource: "../../images/ui/button-prev.png"

                onClicked: {
                    timerController.previousRound();
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Button {
                id: pauseButton

                anchors.centerIn: parent
                width: 80
                height: 80

                style: RoundButtonStyle {}
                iconSource: timerModel.running && !timerModel.paused ? "../../images/ui/button-pause.png" :
                                                 "../../images/ui/button-play.png"

                onClicked: {
                    timerController.togglePause();
                }
            }
        }

        Item {
            Layout.preferredWidth: timerButtonsView.width / 3
            Layout.fillHeight: true
            Button {
                id: nextButton

                anchors.centerIn: parent
                width: 60
                height: 60

                style: RoundButtonStyle {}
                iconSource: "../../images/ui/button-next.png"

                onClicked: {
                    timerController.nextRound();
                }
            }
        }
    }
}
