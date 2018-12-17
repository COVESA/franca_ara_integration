import QtQuick 2.3

Canvas {
    id: cc
    property int lineWidth
    property int leftX
    property int leftY
    property int rightX
    property int rightY
    property int intersectionX
    property int intersectionY

    anchors.fill: parent

    onIntersectionYChanged: cc.requestPaint();

    opacity:0.5

    onPaint: {
        // Get drawing context
        var ctx = getContext("2d");

        ctx.fillStyle = "white"
        ctx.beginPath();
        ctx.clearRect(0, 0, implicitWidth, implicitHeight);
        ctx.fill();

        // Check Outline
        ctx.beginPath();
        ctx.lineWidth = 30;
        ctx.strokeStyle = "white"
        ctx.moveTo(0, 0);
        ctx.lineTo(0, height);
        ctx.lineTo(width,height);
        ctx.lineTo(width, 0);
        ctx.lineTo(0, 0);
        ctx.stroke();

        // The dynamic lane lines
        ctx.beginPath();
        ctx.lineWidth = lineWidth;
        ctx.strokeStyle = "blue"
        ctx.moveTo(leftX, leftY);
        ctx.lineTo(intersectionX, intersectionY);
        ctx.lineTo(rightX, rightY);
        ctx.stroke();

        // Reference
        var lX = 100
        var lY = 750
        var rX = 750
        var rY = 750
        var iX = 350
        var iY = 50
        ctx.beginPath();
        ctx.lineWidth = lineWidth;
        ctx.strokeStyle = "yellow"
        ctx.moveTo(lX, lY);
        ctx.lineTo(iX, iY);  // to intersection
        ctx.lineTo(rX, rY); // ... and back
        ctx.stroke();


        /*
        // Draw a circle
        ctx.beginPath();
        ctx.fillStyle = "orange"
        ctx.strokeStyle = "red"
        ctx.moveTo(width/2+60, height/2);
        ctx.arc(withX*2, height*2, 60, 0, 2*Math.PI, true)
        ctx.fill();
        ctx.stroke();
*/
        // Draw some text
        ctx.beginPath();
        ctx.moveTo(200, 200);
        ctx.lineWidth = 4
        ctx.strokeStyle = "darkblue"
        ctx.font = "50px sans-serif";
        ctx.text("Hello!", width/2, 50);
        ctx.stroke();
    }
}


