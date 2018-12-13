import QtQuick 2.0


Rectangle {
    color: "red"

    Rectangle {
        id: inner
        anchors.centerIn: parent
        width: parent.width - 20
        height: parent.height -20
        color: "white"
    }
}
