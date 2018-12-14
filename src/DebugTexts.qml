// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

import QtQuick 2.0

Item {

    // FIXME: Can Repeaters be used here instead?
    property alias text1 : text1.text
    property alias text2 : text2.text
    property alias text3 : text3.text
    property alias text4 : text4.text
    property alias text5 : text5.text
    property alias text6 : text6.text
    property alias text7 : text7.text
    property alias text8 : text8.text
    property alias text9 : text9.text
    property alias text10 : text10.text
    property alias text11 : text11.text
    property alias text12 : text12.text
    property alias text13 : text13.text

    property string color

    Text {
        id: text1
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
    }
    Text {
        id: text2
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text1.bottom
    }
    Text {
        text: "WAITING"

        id: text3
        font.pixelSize: 40
        color: parent.color
        anchors.top : text2.bottom
    }
    Text {
        text: "WAITING"

        id: text4
        font.pixelSize: 40
        color: parent.color
        anchors.top : text3.bottom
    }
    Text {
        text: "WAITING"

        id: text5
        font.pixelSize: 40
        color: parent.color
        anchors.top : text4.bottom
    }
    Text {
        text: "WAITING"

        id: text6
        font.pixelSize: 40
        color: parent.color
        anchors.top : text5.bottom
    }
    Text {
        id: text7
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text6.bottom
    }
    Text {
        id: text8
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text7.bottom
    }
    Text {
        id: text9
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text8.bottom
    }
    Text {
        id: text10
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text9.bottom
    }
    Text {
        id: text11
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text10.bottom
    }
    Text {
        id: text12
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text11.bottom
    }
    Text {
        id: text13
        text: "WAITING"
        font.pixelSize: 40
        color: parent.color
        anchors.top : text12.bottom
    }
}
