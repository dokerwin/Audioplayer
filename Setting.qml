import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.3
import QtWebView 1.1
import QtQuick 2.0
MessageDialog {
    id: messageDialog
    title:"SETINGS"
    text: "It's so cool that you are using Qt Quick."
    contentItem: Rectangle {

            implicitWidth: 400
            implicitHeight: 400

            Button {
                id: button_add_track

                x: 109
                y: 234
                width: 77
                height: 49
              //  onClicked: appCore.randomTrack()
                background: Rectangle {

                    Text {
                        id: texts
                        anchors.centerIn: parent
                        text: "Add track"
                        font.bold: true
                        font.pixelSize: 15
                        color: button_add_track.pressed ? "#5E5252" : "white"
                    }

                    color: button_add_track.pressed ?  "#50bc2c":"#66D41E"
                    border.color: button_add_track.pressed ? "#66D41E" :"#50bc2c"
                    border.width: 2
                    radius: 25
                }
            }
            Button {
                id: button_1
                width: 54
                height: 49
                anchors.verticalCenterOffset: 20
                anchors.horizontalCenterOffset: 0

                onClicked: {

                    var component = Qt.createComponent("File.qml");
                    if (component.status === Component.Ready) {
                        var dialog = component.createObject(parent,{popupType: 1});
                        dialogConnection.target = dialog


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


        }

    Component.onCompleted: visible = true



}
