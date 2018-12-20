import QtQuick 2.3

Item {
    width: 1920 - 80
    height: 1080

    Connections {
        target: imagesource
        onVehicleIdentified:
        {
            box.visible = recognitionModel.boxY != 0

            db.text2 = "box.height: " + recognitionModel.boxH;
            db.text3 = "box.width: " + recognitionModel.boxW;
            db.text4 = "box.x: " + recognitionModel.boxX;
            db.text5 = "box.y: " + recognitionModel.boxY.toString();
            db.text1 = "Received Frame ID: " + recognitionModel.frameId;
        }
    }

    Connections {
        target: imageprovider
        onUpdateGraphicsImage:
        {
            image.reload();

            db.text6 = "laneLeftX1: " + recognitionModel.laneLeftX1.toString();
            db.text7 = "laneLeftY1: " + recognitionModel.laneLeftY1.toString();
            db.text8 = "laneRightX1: " + recognitionModel.laneRightX1.toString();
            db.text9 = "laneRightY1: " + recognitionModel.laneRightY1.toString();
            db.text10 = "laneLeftX2: " + recognitionModel.laneLeftX2.toString();
            db.text11 = "laneLeftY2: " + recognitionModel.laneLeftY2.toString();
            db.text12 = "laneRightX2: " + recognitionModel.laneRightX2.toString();
            db.text13 = "laneRightY2: " + recognitionModel.laneRightY2.toString();

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

    // Vehicle Identification Box
    VehicleBoundingBox {
        id : box
        height: recognitionModel.boxH
        width: recognitionModel.boxW
        x: recognitionModel.boxX
        y: recognitionModel.boxY
        fillColor: "blue"
        lineColor: "orange"
        visible: true
    }
}
