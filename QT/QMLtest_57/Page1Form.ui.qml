import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias button2: button2
    property alias button1: button1
    property alias textEdit1: textEdit1
    property alias switch1: switch1

    RowLayout {
        anchors.centerIn: parent

        Button {
            id: button1
            text: qsTr("Press Me 1")
        }

        Button {
            id: button2
            text: qsTr("Press Me 2")
            checkable: true
        }
    }

    TextEdit {
        id: textEdit1
        x: 232
        y: 315
        width: 195
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    Switch {
        id: switch1
        x: 217
        y: 102
        text: qsTr("你好")
    }
}

