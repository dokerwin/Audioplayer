import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.3
import QtWebView 1.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Audio drive")




    property string sliderTitle

    property real sliderMin
    property real sliderMax
    property real sliderVal




    /* Using the Connections Object
     * Establish a connection with the application core object
     * */
    Connections {
        target: appCore // Specify the target to connect
        /* Declare and implement the function as a parameter
         * object and with a name similar to the name of the signal
         * The difference is that we add on at the beginning and then write
         * capitalized
         * */

        onSendLabelToQml:{

            track_lbl.text = track


        }
        onControlLevelChanged:{

            volume_lbl.text = "Volume: "+ volume

        }



        onAllTracksToQml:{

            label_alltracks.text = "All tracks: "+  allTracks

        }

    }



    Button {
        id: button
        onClicked: appCore.resive() // Вызов слота
        x: 89
        y: 178
        text: qsTr("Play")
    }

    
    
    Button {

        id: stop_btn
        onClicked: appCore.stop() // Вызов слота
        x: 89
        y: 240
        width: 77
        height: 49
        background: Rectangle {

            Text {
                id: textw
                anchors.centerIn: parent
                text: "Stop"
                font.bold: true
                font.pixelSize: 15
                color: button_1.pressed ? "#5E5252" : "white"
            }

            color: button_1.pressed ?  "#50bc2c":"#66D41E"
            border.color: button_1.pressed ? "#66D41E" :"#50bc2c"
            border.width: 2
            radius: 25
        }
    }

    Label {

        id: track_lbl
        x: 8
        y: 11
        text: qsTr("Label")
    }



    Button {
        id: next_btn
        onClicked: appCore.nextTrack()
        x: 270
        y: 404
        width: 77
        height: 49
        background: Rectangle {

            Text {
                id: textq
                anchors.centerIn: parent
                text: "Next"
                font.bold: true
                font.pixelSize: 15
                color: button_1.pressed ? "#5E5252" : "white"
            }

            color: button_1.pressed ?  "#50bc2c":"#66D41E"
            border.color: button_1.pressed ? "#66D41E" :"#50bc2c"
            border.width: 2
            radius: 25
        }
    }
    

    Slider {
        id: controlLevel
        x: 0
        y: 61




        from: 0; to: 100; stepSize: 1
        value: to * 2

        onValueChanged:appCore.setControlLevel(controlLevel.value)

        ToolTip {
            parent: controlLevel.handle
            visible: controlLevel.pressed
            text: controlLevel.value.toFixed(1)
        }



    }




    Slider {
        id: durtion
        x: 1
        y: 100




        from: 0; to: 100; stepSize: 1
        value: to * 2

        onValueChanged:appCore.setDuration(durtion.value)

        ToolTip {
            parent: durtion.handle
            visible: durtion.pressed
            text: durtion.value.toFixed(1)
        }



    }



    Label {
        id: volume_lbl
        x: 17
        y: 451
        text: qsTr("Volume: ")
    }






    Button {
        width: 77
        height: 49
        anchors.verticalCenterOffset: 20
        anchors.horizontalCenterOffset: 0
        anchors.centerIn: parent
        onClicked: {

            var component = Qt.createComponent("File.qml");
            if (component.status === Component.Ready) {
                var dialog = component.createObject(parent,{popupType: 1});
                dialogConnection.target = dialog
                dialog.show();

            }
        }

        background: Rectangle {

            Text {
                id: st_text
                anchors.centerIn: parent
                text: " Change \ndirectory"
                font.bold: true
                font.pixelSize: 8
                color: button_1.pressed ? "#5E5252" : "white"
            }

            color: button_1.pressed ?  "#50bc2c":"#66D41E"
            border.color: button_1.pressed ? "#66D41E" :"#50bc2c"
            border.width: 2
            radius: 25
        }




    }
    Connections {
        id: dialogConnection
        onVisibleChanged: {
            if(!target.visible)
                console.log(target.returnValue);
        }
    }

    Label {
        id: label_alltracks
        x: 516
        y: 451
        text: qsTr("All tracks: ")
    }




    Button {
        id: button_1
        x: 101
        y: 395
        width: 77
        height: 49
        onClicked: appCore.randomTrack()
        background: Rectangle {

            Text {
                id: text
                anchors.centerIn: parent
                text: "Random"
                font.bold: true
                font.pixelSize: 15
                color: button_1.pressed ? "#5E5252" : "white"
            }

            color: button_1.pressed ?  "#50bc2c":"#66D41E"
            border.color: button_1.pressed ? "#66D41E" :"#50bc2c"
            border.width: 2
            radius: 25
        }
    }




    Playlist{
        x: 399
        y: 31
        width: 224
        height: 398



    }





    Test{
        x: 399
        y: 0
        width: 241
        height: 438


    }











}

