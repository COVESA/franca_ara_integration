import QtQuick 2.3

Item {
    width: 1920 - 80
    height: 1080

    Connections {
        target: imageprovider
        onUpdateGraphicsImage: image.reload();
    }

    ListView {
        width: 100; height: 100
        model: recognitionModel
        Rectangle {
            height: model.modelData.box.height
            width: model.modelData.box.width
            color: model.modelData.box.color
            Text { text: name }
        }
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
