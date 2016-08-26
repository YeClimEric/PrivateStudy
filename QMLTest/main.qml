import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0


Window {
    visible: true
    width:512; height:320
    title: qsTr("Hello World")
    Button{
        id:button
        x:12; y:12
        text: "Start"
        onClicked: {
            status.text = "Button clicked"
        }
    }
    Text {
        id: status
        x:12;y:76
        width:116; height:26
        text: qsTr("waiting...")
        horizontalAlignment: Text.AlignHCenter
    }

    /*测试一下Text*/
//    Text {
//        id: text1
//        width:80
//        text: qsTr("A verry long text")
//        elide: Text.ElideMiddle
//        style: Text.Sunken
//        verticalAlignment: Text.AlignVCenter
//        horizontalAlignment: Text.AlignHCenter
//        font.pixelSize: 20
//        wrapMode: Text.WordWrap
//    }

    /*测试一下矩形框*/
//    Rectangle{
//        id:rect1
//        x:12; y:12
//        width:76; height:96
//        color:"lightsteelblue"
//        MouseArea{
//            width: parent.width
//            height: parent.height
//            onClicked: rect1.visible = !rect2.visible
//        }
//    }
//    Rectangle{
//        id:rect2
//        x:112; y:12
//        width:76; height:96
//        border.color: "lightsteelblue"
//        border.width: 4
//        radius: 8
//    }
//    Rectangle{
//        id:rect3
//        x:212; y:12
//        width:76; height:96
//        gradient: Gradient{
//            GradientStop{position: 0.0; color:"lightsteelblue"}
//            GradientStop{position: 0.5; color:"green"}
//            GradientStop{position: 1.0; color:"red"}
//        }

//        border.color: "slategray"
//    }
    /*测试一下Image*/
//    Image {
//        id: background
//        source: "qrc:/image/background.png"

//        Image {
//            id: wheel1
//            x:10; y:10
//            width: 50; height:50
//            source: "qrc:/image/pinwheel.png"
//            Behavior on rotation{
//                NumberAnimation{
//                    duration: 250
//                }
//            }
//        }
//        Image {
//            x:200; y:200
//            id: wheel2
//            width: 20; height:20
//            fillMode: Image.PreserveAspectCrop
//            clip: true
//            source: "qrc:/image/pinwheel.png"
//            Behavior on rotation{
//                NumberAnimation{
//                    duration: 250
//                }
//            }
//        }
//    }

//        MouseArea{
//            anchors.fill: parent
//            onClicked: {
//                wheel.rotation += 90
//            }
////            onPressed: {
////                wheel.rotation += 10
////                console.log("pressed")
////            }
////            onPressAndHold: {
////                wheel.rotation += 10
////            }
//        }
//    }

}
