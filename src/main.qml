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

            db.text6 = "laneLeftX1: " + recognitionModel.laneLeftX1
            db.text7 = "laneLeftY1: " + recognitionModel.laneLeftY1
            db.text8 = "laneRightX1: " + recognitionModel.laneRightX1
            db.text9 = "laneRightY1: " + recognitionModel.laneRightY1
            db.text10 = "laneLeftX2: " + recognitionModel.laneLeftX2
            db.text11 = "laneLeftY2: " + recognitionModel.laneLeftY2
            db.text12 = "laneRightX2: " + recognitionModel.laneRightX2
            db.text13 = "laneRightY2: " + recognitionModel.laneRightY2
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
        lineColor: "yellow"
        visible: true
        anchors.centerIn: parent
    }

    LaneIndicator {
        id: lane
        color: "#999955"
        width: parent.width
        height: parent.height
        lineWidth: 10
        anchors.fill: parent

        leftX : recognitionModel.laneLeftX1 * xscale
        leftY : recognitionModel.laneLeftY1 * yscale
        rightX : recognitionModel.laneRightX1 * xscale
        rightY : recognitionModel.laneRightY1 * yscale
        intersectionX : recognitionModel.laneRightX2 * xscale
        intersectionY : recognitionModel.laneRightY2 * yscale
    }

    // Set up redraw trigger for lanes
    Connections {
        target: recognitionModel
        onLaneChanged: lane.requestPaint();
    }

    DebugTexts {
        id: db
    }

}
