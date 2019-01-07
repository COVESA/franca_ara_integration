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
    property string coneColorLower
    property string coneColorUpper
    property string lineColorLower
    property string lineColorUpper

    onIntersectionYChanged: cc.requestPaint();

    opacity:0.5

    onPaint: {
        // Get drawing context
        var ctx = getContext("2d");

        ctx.fillStyle = "white"
        ctx.beginPath();
        ctx.clearRect(0, 0, width, height);
        ctx.fill();

        // Draw an outline around the whole item
        ctx.beginPath();
        ctx.lineWidth = 20;
        ctx.strokeStyle = "white"
        ctx.moveTo(0, 0);
        ctx.lineTo(0, cc.height);
        ctx.lineTo(cc.width,cc.height);
        ctx.lineTo(cc.width, 0);
        ctx.lineTo(0, 0);
        ctx.stroke();

        // The real dynamic lane lines
        var coneGradient = ctx.createLinearGradient(0, 480*yscale, 0, 200*yscale); // From lower on screen, to about half way up on screen
        coneGradient .addColorStop("0" , coneColorLower);
        coneGradient .addColorStop("1.0", coneColorUpper);

        var lineGradient = ctx.createLinearGradient(0, 480*yscale, 0, 200*yscale); // From lower on screen, to about half way up on screen
        lineGradient .addColorStop("0" , lineColorLower);
        lineGradient .addColorStop("1.0", lineColorUpper);

        ctx.beginPath();
        ctx.lineWidth = lineWidth;
        if (leftY < cc.height) {
            ctx.moveTo(leftX, cc.height)
            ctx.lineTo(leftX, leftY);
        } else {
            ctx.moveTo(leftX, leftY);
        }

        ctx.lineTo(intersectionX, intersectionY);

        ctx.lineTo(rightX, rightY);
        if (rightY < cc.height) {
            ctx.lineTo(rightX, cc.height)
        }

        ctx.fillStyle = coneGradient;
        ctx.fill();
        ctx.strokeStyle = lineGradient;
        ctx.stroke();
    }
}

