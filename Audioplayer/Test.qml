/*************************************************************************
 *
 * Copyright (c) 2013-2019, Klaralvdalens Datakonsult AB (KDAB)
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.0

Rectangle {
    width: 150; height: 230; color: "white"


    Connections {
        target: appCore

        }














    Component {
        id: nameDelegate
        Text {
            readonly property ListView __lv: ListView.view
            width: parent.width
            text: model.name + model.duration
            font.pixelSize: 5

            MouseArea {
               acceptedButtons: Qt.LeftButton | Qt.RightButton
                onDoubleClicked: {

                   appCore.play_track(model.name)

                }
                anchors.fill: parent
                onClicked: __lv.currentIndex = model.index
            }
        }
    }
//--> slide
    ListView {
        id: listView
        //--> hide
        width: parent.width
        anchors.top: parent.top
        anchors.bottom: label.top
        anchors.bottomMargin: 4

        model: _myModel
        delegate: nameDelegate
        focus: true
        clip: true

        header: Rectangle {
            anchors { left: parent.left; right: parent.right }
            height: 10
            color: "pink"
        }
        footer: Rectangle {
            anchors { left: parent.left; right: parent.right }
            height: 10
            color: "lightblue"
        }
        highlight: Rectangle {
            anchors { left: parent.left; right: parent.right }
            color: "lightgray"
        }//<-- hide
    }

    Text {
        id: label
        y: 211
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        font.pixelSize: 16
        anchors.horizontalCenterOffset: -113
        anchors.bottomMargin: 0
    }
//<-- slide
}
