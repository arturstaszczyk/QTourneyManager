import QtQuick 2.0
import "../"

Row {

    Button {
        id: prevButton
        width: parent.width / 3.0
        height: parent.height
        text: "Prev"

        onClicked: {
            gameContext.prevRound();
        }
    }

    Button {
        id: pauseButton
        width: parent.width / 3.0
        height: parent.height
        text: "Pause"

        onClicked: {
            gameContext.paused = !gameContext.paused
        }
    }

    Button {
        id: nextButton
        width: parent.width / 3.0
        height: parent.height
        text: "Next"

        onClicked: {
            gameContext.nextRound();
        }
    }
}
