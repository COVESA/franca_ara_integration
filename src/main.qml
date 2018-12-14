import QtQuick 2.3

Item {
    width: 1920 - 80
    height: 1080

    Connections {
        target: imageprovider
        onUpdateGraphicsImage: image.reload();
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

    // Test connection to data moddel

    // Old junk
    Rectangle {
        height: recognitionModel.boxH
        width: recognitionModel.boxW
        x: recognitionModel.boxH
        y: recognitionModel.boxW
        color: recognitionModel.boxColor // this is set to "Red"
        //Text { text: name }
    }

    // Directly connected
    Rectangle {
        height: recognitionModel.leftLaneX1
        width: recognitionModel.leftLaneY1
        x: recognitionModel.leftLaneX2 + 500
        y: recognitionModel.leftLaneY2 + 500
        color: "yellow"
    }

    Connections {
        target: myrect
        onLanesChanged: {
            myrect.height = recognitionModel.rightLaneY2;
            myrect.width = recognitionModel.rightLaneY2;
            myrect.x = recognitionModel.rightLaneY2;
            myrect.y = recognitionModel.rightLaneY2;
        }
    }

    // Fixed size, later modified
    Rectangle {
        id: myrect
        height: 200
        width: 300
        x: 400
        y: 500
        color: "blue"
    }
}
