import QtQuick 2.3

Item {
    width: 1920 - 80
    height: 1080



    Connections {
        target: imagesource
        onVehicleIdentified:
        {
           // box.visible = recognitionModel.boxValid
            text1.text = "box.height: " + recognitionModel.boxH.toString();
            text2.text = "box.width: " + recognitionModel.boxL.toString();
            text3.text = "box.x: " + recognitionModel.boxX.toString();
            text4.text = "box.y: " + recognitionModel.boxY.toString();
        }
    }



    Connections {
        target: imageprovider
        onUpdateGraphicsImage:
        {
            image.reload();
/*
           text1.text = "laneLeftX1: " + recognitionModel.laneLeftX1.toString();
            text2.text = "laneLeftY1: " + recognitionModel.laneLeftY1.toString();
            text3.text = "laneRightX1: " + recognitionModel.laneRightX1.toString();
            text4.text = "laneRightY1: " + recognitionModel.laneRightY1.toString();
            text5.text = "laneLeftX2: " + recognitionModel.laneLeftX2.toString();
            text6.text = "laneLeftY2: " + recognitionModel.laneLeftY2.toString();
            text7.text = "laneRightX2: " + recognitionModel.laneRightX2.toString();
            text8.text = "laneRightY2: " + recognitionModel.laneRightY2.toString();
*/
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
    Rectangle {
        id : box
        height: recognitionModel.boxH
        width: recognitionModel.boxW
        x: recognitionModel.boxX
        y: recognitionModel.boxY
        color: "red"
        visible: true
    }




/*
    // Lane representation
    Rectangle {
        height: 200
        width: 200
        x: recognitionModel.laneLeftX1
        y: recognitionModel.laneLeftY1
        color: "yellow"
    }

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

    Text {
        id: text1
        text: "WAITING"
        font.pixelSize: 40
    }
    Text {
        id: text2
        text: "WAITING"

        font.pixelSize: 40
        anchors.top : text1.bottom
    }
    Text {
        text: "WAITING"

        id: text3
        font.pixelSize: 40
        anchors.top : text2.bottom
    }
    Text {
        text: "WAITING"

        id: text4
        font.pixelSize: 40
        anchors.top : text3.bottom
    }
    Text {
        text: "WAITING"

        id: text5
        font.pixelSize: 40
        anchors.top : text4.bottom
    }
    Text {
        text: "WAITING"

        id: text6
        font.pixelSize: 40
        anchors.top : text5.bottom
    }
    Text {
        id: text7
        text: "WAITING"

        font.pixelSize: 40
        anchors.top : text6.bottom
    }
    Text {
        id: text8
        text: "WAITING"

        font.pixelSize: 40
        anchors.top : text7.bottom
    }


}
