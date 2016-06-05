import QtQuick 2.0
import "../"

Row {

    Button {
        id: prevButton
        width: parent.width / 3.0
        height: parent.height
        text: "Prev"

        onClicked: {
            mainScreenController.prevRound();
        }
    }

    Button {
        id: pauseButton
        width: parent.width / 3.0
        height: parent.height
        text: "Pause"

        onClicked: {
            mainScreenController.isPaused = !mainScreenController.isPaused
        }
    }

    Button {
        id: nextButton
        width: parent.width / 3.0
        height: parent.height
        text: "Next"

        onClicked: {
            mainScreenController.nextRound();
        }
    }
}
