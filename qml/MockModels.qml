import QtQuick 2.0

Item {
    Component.onCompleted: {
        _hostAddress = app.isCppAvailable ? hostAddressModel : mockHostAddressModel
        _timer = app.isCppAvailable ? timerModel : mockTimerModel
    }

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
    }
}
