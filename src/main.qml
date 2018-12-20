import QtQuick 2.3

Rectangle {
    width: 1920 - 80
    height: 1080
    color: "black"  // Use black background if there is any flickering

    // Scaling of images & coordinates
    property double xscale : width / 640.0
    property double yscale : height / 480.0

    VideoImage {
        id: video
    }

    DebugTexts {
        id: db
        color: "black"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 10
        anchors.topMargin: 10
    }
}
