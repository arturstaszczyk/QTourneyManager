import QtQuick 2.0
import "../"

Column {

    Button {
        id: prevButton
        width: parent.width
        height: parent.height / 3.0
        text: "Prev"

        onClicked: {
            gameContext.prevRound();
        }
    }

    Button {
        id: pauseButton
        width: parent.width
        height: parent.height / 3.0
        text: "Pause"

        onClicked: {
            gameContext.paused = !gameContext.paused
        }
    }

    Button {
        id: nextButton
        width: parent.width
        height: parent.height / 3.0
        text: "Next"

        onClicked: {
            gameContext.nextRound();
        }
    }
}
