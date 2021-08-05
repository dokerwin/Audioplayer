
/*************************************************************************
 *
 * Copyright (c) 2019, Klaralvdalens Datakonsult AB (KDAB)
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.0

ListView {
    width: 100
    height: 200
    model: _myModel

    delegate: Rectangle {
        color: Qt.rgba(0.9,0.9,0.9)
        height: childrenRect.height
        width: parent.width



        Text {

           text: model.name + model.duration
        }


        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onDoubleClicked: {
               console.log(model.name);

            }
        }
    }
}
