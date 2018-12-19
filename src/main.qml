import QtQuick 2.3

Item {
    width: 1920 - 80
    height: 1080

    // Scaling of images & coordinates
    property double xscale : width / 640.0
    property double yscale : height / 480.0


    Connections {
        target: imagesource
        onVehicleIdentified:
        {
            box.visible = recognitionModel.boxY != 0

            db.text2 = "box.x: " + recognitionModel.boxX;
            db.text3 = "box.y: " + recognitionModel.boxY;
            db.text4 = "box.height: " + recognitionModel.boxH;
            db.text5 = "box.width: " + recognitionModel.boxW;
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
        height: recognitionModel.boxH * yscale
        width: recognitionModel.boxW * xscale
        x: recognitionModel.boxX
        y: recognitionModel.boxY
        fillColor: "blue"
        lineColor: "orange"
        visible: true
        anchors.centerIn: parent
    }


/*
    // Not sure this is getting triggered...
    Connections {
        target: recognitionModel
        onLaneChanged: lane.requestPaint();
    }


    LaneIndicator {
        id: lane
        x: 100
        y: 500
        width: 1300
        height: 1000
        lineWidth: 20
        leftX : recognitionModel.laneLeftX1
        leftY : recognitionModel.laneleftY1
        rightX : recognitionModel.laneRightX1
        rightY : recognitionModel.laneRightY1
        intersectionX : recognitionModel.laneRightX2
        intersectionY : recognitionModel.laneRightY2
    }
*/
    DebugTexts {
        id: db
    }

}
