import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.3
import QtWebView 1.1
import QtQuick 2.0
import "Buttons/" as MyButton

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Audio drive")

    property string sliderTitle

    property real sliderMin
    property real sliderMax
    property real sliderVal


    Image {
        width: 150; height: 150
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectCrop

        source: "file:///C:/Users/z.kulbachenko/Documents/Audioplayer-main/build-Audioplayer-Desktop_x86_windows_msvc2019_pe_32bit-Debug/image/icon.png"

    }


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

        onDurationChanged:{

            function secondsToTime(e){
                var h = Math.floor(e / 3600).toString().padStart(2,'0'),
                    m = Math.floor(e % 3600 / 60).toString().padStart(2,'0'),
                    s = Math.floor(e % 60).toString().padStart(2,'0');

                return h + ':' + m + ':' + s;
                //return `${h}:${m}:${s}`;
            }

            function formatSeconds(s) {
                let minutes = ~~(s / 60);
                let seconds = ~~(s % 60);
                return minutes + ':' + seconds;
              }



            durtion.value = duration_;
            durtion_lbl.text = "Duration: "+ formatSeconds(duration_);










        }


        onAllTracksToQml:{

            label_alltracks.text = "All tracks: "+  allTracks

        }

    }






    MyButton.Stop_btn{

    }




    Label {

        id: track_lbl
        x: 221
        y: 11
        text: qsTr("Label")
    }


    

    Slider {
        id: controlLevel
        x: 0
        y: 106
        width: 251
        height: 20




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
        x: 0
        y: 435
        width: 640
        height: 10

        from: 0; to: 1000; stepSize: 1
       // value: to * 2

        onValueChanged:appCore.setDuration(durtion.value)

        ToolTip {
            id: tip
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








    Label {
        id: label_alltracks
        x: 516
        y: 451
        text: qsTr("All tracks: ")
    }








    Test{
        x: 401
        y: 26
        width: 229
        height: 397
    }

    Label {
        id: volume_lbl1
        x: 494
        y: 11
        text: qsTr("Tracks")
    }




    Setting_button{



        x: 0
        y: 0



    }

    Label {
        id: durtion_lbl
        x: 286
        y: 451
        text: qsTr("Duration: ")
    }

    MyButton.Play_btn {
        x: 110
        y: 220
    }

    MyButton.Next_btn {
        x: 163
        y: 220
    }

    MyButton.Prev_btn {
        x: 50
        y: 220
    }

    Button {
        id: stop_btn
        x: 109
        y: 280
        width: 48
        height: 49
        background: Rectangle {
            color: button_1.pressed ?  "#50bc2c":"#66D41E"
            radius: 25
            border.color: button_1.pressed ? "#66D41E" :"#50bc2c"
            border.width: 2
            Text {
                id: textw
                color: button_1.pressed ? "#5E5252" : "white"
                text: "Stop"
                font.pixelSize: 15
                font.bold: true
                anchors.centerIn: parent
            }
        }
        onClicked: appCore.stop()
    }

    Button {
        id: button_1
        x: 110
        y: 159
        width: 49
        height: 49
        background: Rectangle {
            color: button_1.pressed ?  "#50bc2c":"#66D41E"
            radius: 25
            border.color: button_1.pressed ? "#66D41E" :"#50bc2c"
            border.width: 2
            Text {
                id: texts
                color: button_1.pressed ? "#5E5252" : "white"
                text: "R"
                font.pixelSize: 15
                font.bold: true
                anchors.centerIn: parent
            }
        }
        onClicked: appCore.randomTrack()
    }



}



