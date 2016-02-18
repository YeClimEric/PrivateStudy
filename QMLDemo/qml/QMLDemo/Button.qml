import QtQuick 2.0

Rectangle{
    width: 48; height: 48;
    color: "blue"
    border.color: Qt.lighter(color)

    MouseArea{
        anchors.fill: parent
        drag.target: parent
    }
}

//Rectangle{
//    id: root

//    property alias text: label.text
//    signal clicked

//    width: 116; height: 26;
//    color: "lightsteelblue"
//    border.color: "slategrey"

//    Text {
//        id: label
//        anchors.centerIn: parent
//        text: qsTr("Start")
//    }

//    MouseArea{
//        anchors.fill: parent
//        onClicked: {
//            root.clicked()
//        }
//    }
//}
