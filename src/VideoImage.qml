// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

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

            db.text2 = "box.x: " + recognitionModel.boxX;
            db.text3 = "box.y: " + recognitionModel.boxY;
            db.text4 = "box.height: " + recognitionModel.boxH;
            db.text5 = "box.width: " + recognitionModel.boxW;
            db.text1 = "Video Frame #: " + recognitionModel.frameId;
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
        lineColor: "red"
        visible: true
    }

    LaneIndicator {
        id: lane
        coneColorLower: "#F0FF8000"
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

            db.text6 = "laneLeftX1: " + recognitionModel.laneLeftX1;
            db.text7 = "laneLeftY1: " + recognitionModel.laneLeftY1;
            db.text8 = "laneRightX1: " + recognitionModel.laneRightX1;
            db.text9 = "laneRightY1: " + recognitionModel.laneRightY1;
            db.text10 = "laneLeftX2: " + recognitionModel.laneLeftX2;
            db.text11 = "laneLeftY2: " + recognitionModel.laneLeftY2;
            db.text12 = "laneRightX2: " + recognitionModel.laneRightX2;
            db.text13 = "laneRightY2: " + recognitionModel.laneRightY2;

            lane.requestPaint();

        }
    }
}
