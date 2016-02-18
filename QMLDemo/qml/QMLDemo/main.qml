import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.0

Rectangle{
    id: root
    width: 220; height: 220
    color: "black"

    Button{
        x:10; y:10
        width: 200; height: 200
        BlueButton{
            id: btn1
            width: 120
//            anchors.fill: parent
            anchors.margins: 8;
        }

        BlueButton{
            id: btn2
            width: 120
//            anchors.fill: parent
            anchors.top: btn1.bottom
//            anchors.margins: 30;
            anchors.horizontalCenterOffset: 30
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Image {
        id: aa
        source: "images/rocket.png"
    }


}

//Rectangle {
//    id: root
//    width: 252
//    height: 252
//    color: "black"
//    property variant colorArray: ["#00bde3", "#67c111", "#ea7025"]

//    Grid {
//        anchors.fill: parent
//        anchors.margins: 8
//        spacing: 4
//        Repeater {
//            model: 16
//            Rectangle {
//                width: 56; height: 56
//                property int colorIndex: Math.floor(Math.random()*3)
//                color: root.colorArray[colorIndex]
//                border.color: Qt.lighter(color)
//                Text {
//                    anchors.centerIn: parent
//                    color: "black"
//                    text: "Cell " + index
//                }
//            }
//        }
//    }
//}

//Rectangle{
//    width: 360; height: 360;
//    //外部引用组件，使用文件名作为组件名
//    //一个文件中只能包含一个组件元素
//    Button{
//        id: button
//        x:12; y:12;
//        text: "Start"

//        onClicked: {
//            status.text = "Button clicked!"
//        }
//    }

//    Text {
//        id: status
//        x:12;y:76
//        width: 116; height: 26
//        text: qsTr("waiting")
//        horizontalAlignment: Text.AlignHCenter
//    }

//}

//Rectangle{
//    id: rect
//    width: 100
//    height: 150
//    color: "lightsteelblue"
//    border{
//        color: "#FF0000"
//        width: 4
//    }

//    gradient: Gradient{
//        GradientStop{position: 0.0; color: "red"}
//        GradientStop{position: 0.33; color: "yellow"}
//        GradientStop{position: 1.0; color: "green"}
//    }

//    radius: 8
//}

//Text {
//    id: label
//    width: 200
//    height: 20
//    property int spacePresses: 0
//    text: "Space pressed: " + spacePresses + " times"
//    //on+属性名+Changed
//    onTextChanged: console.log("text changed to:",text)
//    //接收键盘事件
//    focus: true
//    Keys.onSpacePressed: {
//        increment();
//    }

//    Keys.onEscapePressed:{
//        label.text = '';
//    }

//    function increment(){
//        spacePresses += 1
//    }

//}

//Window{
//    id:root;
//    visible:true;
//    width:460;
//    height:288;
//    Image{
//        id:bg;
//        width:parent.width;
//        height:parent.height;
//        source: "qrc:/images/recket"
//    }

//    Text {
//        y:bg.y + bg.height + 20;
//        text: qsTr("text");
//        Font.pixelSize: 30;
//    }
//}

//Rectangle{
//    id: root
//    width: 360
//    height: 360
//    color:"#D8D8D8"
//    Image{
//        id:recoket
//        x:(parent.width - width)/2
//        y:40
//        source: 'images/rocket.png'
//    }

//    Text {
//        y:recoket.y + recoket.height + 20
//        width: root.width
//        horizontalAlignment: Text.AlignHCenter
//        text: qsTr("Hello World ")
//        anchors.centerIn: parent
//    }
////    MouseArea {
////        anchors.fill: parent
////        onClicked: {
////            Qt.quit();
////        }
////    }
//}


