import QtQuick 2.3

Item {
    width: 1920 - 80
    height: 1080

    Connections {
        target: imageprovider
        onUpdateGraphicsImage: image.reload();
    }

// Test connection to data moddel
    Rectangle {
        height: recognitionModel.boxH
        width: recognitionModel.boxW
        x: recognitionModel.boxH
        y: recognitionModel.boxW
        color: recognitionModel.boxColor
        //Text { text: name }
    }

    Image {
        id: image
        anchors.fill: parent
        source: "image://imageprovider"
        cache: false
        asynchronous: true
        function reload() {
            var oldSource = source;
            source = "";
            source = oldSource;
        }
    }
}
