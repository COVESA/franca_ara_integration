import QtQuick 2.3

Item {
    width: 1920 - 80
    height: 1080

    Connections {
        target: imageprovider
        onNewFrameReceived: image.reload();
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
