import QtQuick 2.7

Page1Form {
    button1.onClicked: {
        console.log("Button 1 clicked.");
        textEdit1.text="A"
    }
    button2.onClicked: {
        console.log("Button 2 clicked.");
        textEdit1.text="B"
    }
    switch1.onClicked: {
        textEdit1.text = switch1.checked
    }
}
