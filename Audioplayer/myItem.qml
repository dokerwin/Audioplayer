
import QtQuick 2.2
import QtQuick.Controls 1.5
import QtQml.Models 2.2

Item {

    id:parentiem;
    x:100;
    y:200;


    ItemSelectionModel {
        id: sel
        model: fileSystemModel
    }

    TreeView {
        id: view
        anchors.fill: parent
        anchors.margins: 2 * 12 + row.height
        model: fileSystemModel
        rootIndex: rootPathIndex
        selection: sel

        TableViewColumn {
            title: "Name"
            role: "fileName"
            resizable: true
        }

        TableViewColumn {
            title: "Size"
            role: "size"
            resizable: true
            horizontalAlignment : Text.AlignRight
            width: 70
        }

        TableViewColumn {
            title: "Permissions"
            role: "displayableFilePermissions"
            resizable: true
            width: 100
        }

        TableViewColumn {
            title: "Date Modified"
            role: "lastModified"
            resizable: true
        }

        onActivated : {
            var url = fileSystemModel.data(index, FileSystemModel.UrlStringRole)
            Qt.openUrlExternally(url)
        }
    }


}
