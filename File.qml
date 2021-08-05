import QtQuick 2.2

import QtQuick.Dialogs 1.3


Item {
    id: name

Connections {
    target: appCore // Specify the target to connect
    /* Declare and implement the function as a parameter
     * object and with a name similar to the name of the signal
     * The difference is that we add on at the beginning and then write
     * capitalized
     * */



}

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        selectFolder: true
        onAccepted: {

        appCore.setDirectory(fileDialog.fileUrls)

            console.log("You chose: " + fileDialog.fileUrls)
            //acceptDialog();
        }
        onRejected: {
            console.log("rejected")
            //rejectDialog();
        }
        Component.onCompleted: visible = true
    }


}
