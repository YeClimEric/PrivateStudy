import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0


Window {
    visible: true
    width:480; height:320
    title: qsTr("Hello World")

    /*Shape-Shifting Delegates*/
//    ShapeShiftingDelegate{

//    }

    ListModelGridViewDelegate{

    }

    /*简单的View-delegate*/
//    ListView{
//        anchors.fill: parent
//        anchors.margins: 20

//        clip: true
//        model:20
//        spacing: 5
//        delegate:numberDelegate
//        //设置停止位置，测试发现会SnapOneItem影响到鼠标滚轮操作
//        snapMode: ListView.SnapToItem
//        //设置翻到首页或者尾页时的效果
////        boundsBehavior: Flickable.StopAtBounds
//        orientation: ListView.Vertical/*ListView.Horizontal*/
//        //水平状态下的方向
////        layoutDirection: Qt.RightToLeft
//        //设置捕获键盘焦点与高亮
//        focus: true
//        highlight: highlightComponent
//        /*
//          StrictlyEnforceRange:始终显示高亮，如果高亮的Item不在可视范围内，则自动切换
//          NoHightlightRange:高亮与视图中的元素距离不相关
//*/
//        highlightRangeMode: ListView.ApplyRange//ListView.StrictlyEnforceRange//ListView.NoHighlightRange
//        highl
//    }

//    Component{
//        id:highlightComponent
//        Rectangle{
//            width: ListView.view.width
//            height:ListView.view.height
//            color:"yellow"
//        }
//    }

//    Component{
//        id:numberDelegate

//        Item{
//            width: 40; height:40

////            color:"lightGreen"
//            Text {
//                anchors.centerIn: parent
//                font.pixelSize: 10
//                text: index
//            }
//        }

//    }



    /*简单的M-V模式*/
//    Column{
//        spacing: 2

//        Repeater{
//            model:ListModel{
//                ListElement { name: "Mercury"; surfaceColor: "gray" }
//                ListElement { name: "Venus"; surfaceColor: "yellow" }
//                ListElement { name: "Earth"; surfaceColor: "blue" }
//                ListElement { name: "Mars"; surfaceColor: "orange" }
//                ListElement { name: "Jupiter"; surfaceColor: "orange" }
//                ListElement { name: "Saturn"; surfaceColor: "yellow" }
//                ListElement { name: "Uranus"; surfaceColor: "lightBlue" }
//                ListElement { name: "Neptune"; surfaceColor: "lightBlue" }
//            }

//            //model:["Enterprise", "Colombia", "Challender", "Discovery", "Endeavour", "Atlantis"]


//            Rectangle{
//                width:100; height:20
//                radius: 3
//                border.color:"black"
//                border.width: 1
//                color: "green"

//                Text {
//                    anchors.centerIn: parent
//                    text: name
////                    color:surfaceColor
//                }
//                Rectangle{
//                    anchors.left: parent.left
//                    anchors.verticalCenter: parent.verticalCenter
//                    anchors.leftMargin: 2

//                    width:16; height:16
//                    radius: 8
//                    border.color: "black"
//                    border.width: 1

//                    color: surfaceColor
//                }
//            }
//        }
//    }


/*输入组件测试*/
//    Rectangle {
//        x: 10; y:10
//        width: 96; height: input.height + 8
//        color: "lightsteelblue"
//        border.color: "gray"

//        property alias text: input.text
//        property alias input: input

//        TextInput {
//            id: input
//            anchors.fill: parent
//            anchors.margins: 4
//            focus: true
//        }
//    }


    //一个可以拖拽的框
//    Rectangle{
//        id:rect1
//        width:48; height:48
//        color:"lightsteelblue"

//        MouseArea{
//            id:mouseRegion
//            anchors.fill: parent
//            property variant clickPos: "1,1"
//            onPressed: {
//                clickPos = Qt.point(mouse.x, mouse.y)
//            }

//            onPositionChanged: {
//                var delta = Qt.point(mouse.x - clickPos.x, mouse.y - clickPos.y)
//                rect1.x += delta.x
//                rect1.y += delta.y
//            }
//        }
//    }

//    Button{
//        id:button
//        x:12; y:12
//        text: "Start"
//        onClicked: {
//            status.text = "Button clicked"
//        }
//    }
//    Text {
//        id: status
//        x:12;y:76
//        width:116; height:26
//        text: qsTr("waiting...")
//        horizontalAlignment: Text.AlignHCenter
//    }

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
