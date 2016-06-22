import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "qrc:/qml/Styles"

Row {

    Button {
        id: prevButton
        width: parent.width / 3.0
        height: parent.height
        text: "Prev"

        style: ButtonStyle {
            label: Component {
                BigButtonTextStyle{
                    text: prevButton.text
                }
            }
        }

        onClicked: {
            timerController.previousRound();
        }
    }

    Button {
        id: pauseButton
        width: parent.width / 3.0
        height: parent.height
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
        width: parent.width / 3.0
        height: parent.height
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
