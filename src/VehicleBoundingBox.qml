// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

import QtQuick 2.0

Item {
    id: vehiclebox

    // Default values that can be overridden by instance
    property string fillColor : "blue"
    property string lineColor : "blue"
    property int frameLineWidth : 8
    property double boxOpacity : 0.1
    property int lineOpacity : 1.0

    // This is the semi-translucent background
    Rectangle {
        anchors.fill: parent
        color: parent.fillColor
        opacity: parent.boxOpacity
    }

    // Each "line" is drawn as a small rectangle
    Rectangle {
        id: top
        color: parent.lineColor  // default, overridden by instance
        width : parent.width
        height: parent.frameLineWidth
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        opacity: lineOpacity
    }

    Rectangle {
        id: left
        color: parent.lineColor// default, overridden by instance
        width : parent.frameLineWidth
        height: parent.height
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom : parent.bottom
        opacity: lineOpacity

    }

    Rectangle {
        id: right
        color: parent.lineColor// default, overridden by instance
        width : parent.frameLineWidth
        height: parent.parent.height
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom : parent.bottom
        opacity: lineOpacity
    }

    Rectangle {
        id: bottom
        color: parent.lineColor  // default, overridden by instance
        width : parent.width
        height: parent.frameLineWidth
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        opacity: lineOpacity
    }
}
