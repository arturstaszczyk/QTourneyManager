import QtQuick 2.0

Item {
    Component.onCompleted: {
        if(!app.isCppAvailable)
        {
            _hostAddress = mockHostAddressModel
        }
    }

    Item {
        id: mockHostAddressModel

        property string address: "127.0.0.1"
        property bool isValid: true
    }
}
