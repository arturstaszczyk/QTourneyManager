import QtQuick 2.0

Item {

    property alias mockHostAddressModel: mockHostAddressModel
    property alias mockTimerModel: mockTimerModel

    Item {
        id: mockHostAddressModel

        property string address: "127.0.0.1"
        property bool isValid: true
    }

    Item {
        id: mockTimerModel
        property int smallBlind: 2
        property int bigBlind: 3
        property string timeString: "00:12"

        property int activeRound: 1

        property var blinds: [
            { smallBlind: 2, bigBlind: 3, timeString: "00:12" },
            { smallBlind: 2, bigBlind: 3, timeString: "00:12" },
            { smallBlind: 2, bigBlind: 3, timeString: "00:12" },
        ]
    }
}
