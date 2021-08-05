import QtQuick 2.0

  //Implementation of the Button control.
  Item {
      id: button
      width: 47
      height: 47
      property alias text: innerText.text
      signal clicked

      Image {
          id: backgroundImage
          anchors.fill: parent
          source: (button.enabled ? "file:///C:/Users/z.kulbachenko/Documents/Audioplayer-main/build-Audioplayer-Desktop_x86_windows_msvc2019_pe_32bit-Debug/image/setting.png" : "file:///C:/Users/z.kulbachenko/Documents/Audioplayer-main/build-Audioplayer-Desktop_x86_windows_msvc2019_pe_32bit-Debug/image/setting_1.png")
      }

      Text {
          id: innerText
          anchors.centerIn: parent
          color: "white"
          font.bold: true
      }

      //Mouse area to react on click events
      MouseArea {
          anchors.fill: button
          onClicked: {

                  var component = Qt.createComponent("Setting.qml");
                  if (component.status === Component.Ready) {
                      var dialog = component.createObject(parent,{popupType: 1});
                      dialogConnection.target = dialog



                  }}
          onPressed: {
              backgroundImage.source = "file:///C:/Users/z.kulbachenko/Documents/Audioplayer-main/build-Audioplayer-Desktop_x86_windows_msvc2019_pe_32bit-Debug/image/setting_pressed.png"

          }
          onReleased: {
              backgroundImage.source = (button.enabled ? "file:///C:/Users/z.kulbachenko/Documents/Audioplayer-main/build-Audioplayer-Desktop_x86_windows_msvc2019_pe_32bit-Debug/image/setting_1" : "file:///C:/Users/z.kulbachenko/Documents/Audioplayer-main/build-Audioplayer-Desktop_x86_windows_msvc2019_pe_32bit-Debug/image/setting.png")
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
