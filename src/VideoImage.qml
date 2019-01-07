import QtQuick 2.0

Item {
    anchors.fill: parent
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

    Connections {
        target: imagesource
        onVehicleIdentified:
        {
            box.visible = recognitionModel.boxY != 0

            db.text1 = "Video Frame #: " + recognitionModel.frameId;
            db.text2 = "Vehicle recognized, x: " + recognitionModel.boxX;
            db.text3 = "Vehicle recognized, y: " + recognitionModel.boxY;
            db.text4 = "Vehicle recognized, h: " + recognitionModel.boxH;
            db.text5 = "Vehicle recognized, w: " + recognitionModel.boxW;
        }
    }

    Connections {
        target: imageprovider
        onUpdateGraphicsImage: image.reload();
    }

    // Vehicle Identification Box
    VehicleBoundingBox {
        id : box
        height: recognitionModel.boxH * yscale
        width: recognitionModel.boxW * xscale
        x: recognitionModel.boxX * xscale
        y: recognitionModel.boxY * yscale
        fillColor: "blue"
        lineColor: "yellow"
        visible: true
    }

    LaneIndicator {
        id: lane
        coneColorLower: "#F0FF7000"
        coneColorUpper: "#20FFFF55"
        lineColorLower: "#F0FFFF00"
        lineColorUpper: "#20808000"
        width: parent.width
        height: parent.height
        lineWidth: 20
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
        onLaneChanged: {

            db.text6 = "Left lane X1: " + recognitionModel.laneLeftX1;
            db.text7 = "Left lane Y1: " + recognitionModel.laneLeftY1;
            db.text8 = "Left lane X2: " + recognitionModel.laneLeftX2;
            db.text9 = "Left lane Y2: " + recognitionModel.laneLeftY2;
            db.text10 = "Right lane X1: " + recognitionModel.laneRightX1;
            db.text11 = "Right lane Y1: " + recognitionModel.laneRightY1;
            db.text12 = "Right lane X2: " + recognitionModel.laneRightX2;
            db.text13 = "Right lane Y2: " + recognitionModel.laneRightY2;

            lane.requestPaint();
        }
    }
}
