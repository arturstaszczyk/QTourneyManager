import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import "../Styles"

Rectangle {
    id: timerButtonsView

    border.color: "red"
    border.width: 5

    RowLayout {
        spacing: 0

        Button {
            id: prevButton

            Layout.preferredWidth: timerButtonsView.width / 3.0
            Layout.preferredHeight: timerButtonsView.height

            text: "Prev"

            style: ButtonStyle {
                label: Component {
                    BigButtonTextStyle{
                        text: prevButton.text
                    }
                }
                background: Rectangle {
                    id: back
                    radius: 30
                    anchors.fill: parent
                    gradient: Gradient {
//                        anchors.fill: parent
//                        start: Qt.point(0, 0);
//                        end: Qt.point(0, back.height)
                        GradientStop { position: 0.0; color: "white" }
                        GradientStop { position: 1.0; color: "black" }
                    }
                }
            }

            onClicked: {
                timerController.previousRound();
            }
        }

        Button {
            id: pauseButton
            Layout.preferredWidth: timerButtonsView.width / 3.0
            Layout.preferredHeight: timerButtonsView.height
            text: "Pause"
            style: ButtonStyle {
                label: Component {
                    BigButtonTextStyle{
                        text: pauseButton.text
                    }
                }
            }


            onClicked: {
                timerController.togglePause();
            }
        }

        Button {
            id: nextButton
            Layout.preferredWidth: timerButtonsView.width / 3.0
            Layout.preferredHeight: timerButtonsView.height
            text: "Next"
            style: ButtonStyle {
                label: Component {
                    BigButtonTextStyle{
                        text: nextButton.text
                    }
                }
            }

            onClicked: {
                timerController.nextRound();
            }
        }
    }
}
