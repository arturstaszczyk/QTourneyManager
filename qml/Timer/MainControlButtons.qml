import QtQuick 2.0
import "../"

Row {

    Button {
        id: prevButton
        width: parent.width / 3.0
        height: parent.height
        text: "Prev"

        onClicked: {
            timerController.previousRound();
        }
    }

    Button {
        id: pauseButton
        width: parent.width / 3.0
        height: parent.height
        text: "Pause"

        onClicked: {
            timerController.togglePause();
        }
    }

    Button {
        id: nextButton
        width: parent.width / 3.0
        height: parent.height
        text: "Next"

        onClicked: {
            timerController.nextRound();
        }
    }
}
