import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic


ApplicationWindow {
    id: operationwindow
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Operations")
    
     property string input : ""
     property bool isEnabled: false
    
    property color dark: "#262626"
    property color reallyLight: "#e7e7e7"
    property color light: "#e0e0e0"

    GridLayout {
        id: grid
        columns: width < 400 ? 1 : 2
        rowSpacing: 0
        columnSpacing: 0
        anchors.fill: parent

        Rectangle {
            id: rectangle1
            color:  operationwindow.reallyLight 
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                Label {
                    id: text1
                    color: operationwindow.dark
                    font.pixelSize: 120
                    fontSizeMode: Text.Fit
                    text: qsTr("Select a function to perform")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Label {
                    id: textNote
                    color: operationwindow.dark
                    font.pixelSize: 100
                    fontSizeMode: Text.Fit
                    text: qsTr("For negative numbers, delete the space after \"-\"")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                     Label {
                    id: textSwitch
                    color: operationwindow.dark
                    font.pixelSize: 80
                    fontSizeMode: Text.Fit
                    text: ("Switch allows you to switch to 0, operators and ()")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                 Label {
                    id: textInput
                    color: operationwindow.dark
                    font.pixelSize: 25
                    fontSizeMode: Text.Fit
                    text: qsTr("Current input: "+ operationwindow.input)
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }

       GridLayout {
            id: rectangle2
          columns: 3
          columnSpacing: 0
          rowSpacing: 20
           Button {
            id: buttonEnter
            text: ("Confirm Input")
            Layout.bottomMargin: 16
            contentItem: Text {
                text: buttonEnter.text
                color:  operationwindow.light 
                font: buttonEnter.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    implicitWidth: 120
                    implicitHeight: 36
                    radius: 8
                    color: operationwindow.dark 
                }    
                onClicked:{
                    var component = Qt.createComponent("OperationsResults.qml")
                  var windowResult = component.createObject()
                  windowResult.input= operationwindow.input;
                     windowResult.show()   
                operationwindow.hide()    
                }            
                }
          Button {
                    id: buttonDelete
                    text: ("Delete")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: buttonDelete.text
                        color: operationwindow.light 
                        font: buttonDelete.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  operationwindow.dark 
                    }
                    onClicked:
                    operationwindow.input = operationwindow.input.substring(0, operationwindow.input.length - 1);
                }
                 Button {
                    id: buttonSwitch
                 text: ("Switch")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: buttonSwitch.text
                        color: operationwindow.light 
                        font: buttonSwitch.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: operationwindow.dark 
                    }
                    onClicked:
                    operationwindow.isEnabled = !operationwindow.isEnabled
                }
                Button {
                    id: button1
                    text: if(operationwindow.isEnabled == true){
                        ("+")
                        }
                    else{
                        ("1")}
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button1.text
                        color: operationwindow.light 
                        font: button1.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: operationwindow.dark 
                    }

                    onClicked:  
                    if(operationwindow.isEnabled== true){
                        operationwindow.input+=(" + ")}
                        else{
                            operationwindow.input+=("1")
                        }
                }

                Button {
                    id: button2
                    text: if(operationwindow.isEnabled == true){
                        ("-")
                        }
                    else{
                        ("2")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button2.text
                        color: operationwindow.light 
                        font: button2.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: operationwindow.dark 
                    }

                    onClicked:  if(operationwindow.isEnabled== true){
                        operationwindow.input+=(" - ")}
                        else{
                            operationwindow.input+=("2")
                        }
                }
                 Button {
                    id: button3
                    text: if(operationwindow.isEnabled == true){
                        ("*")
                        }
                    else{
                        ("3")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button3.text
                        color:  operationwindow.light
                        font: button3.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: operationwindow.dark
                    }

                    onClicked: 
                    if(operationwindow.isEnabled== true){
                        operationwindow.input+=(" * ")}
                        else{
                            operationwindow.input+=("3")
                        }
                }
                 Button {
                    id: button4
                    text: if(operationwindow.isEnabled == true){
                        ("/")
                        }
                    else{
                        ("4")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button4.text
                        color:  operationwindow.light 
                        font: button4.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  operationwindow.dark 
                    }
                    onClicked: 
                    if(operationwindow.isEnabled== true){
                        operationwindow.input+=(" / ")}
                        else{
                            operationwindow.input+=("4")
                        }
                }
            Button {
                    id: button5
                    text: if(operationwindow.isEnabled == true){
                        ("%")
                        }
                    else{
                        ("5")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button5.text
                        color: operationwindow.light
                        font: button5.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: operationwindow.dark 
                    }
                    onClicked:  if(operationwindow.isEnabled== true){
                        operationwindow.input+=(" % ")}
                        else{
                            operationwindow.input+=("5")
                        }
                }
              Button {
                    id: button6
                    text: if(operationwindow.isEnabled == true){
                        ("0")
                        }
                    else{
                        ("6")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button6.text
                        color: operationwindow.light
                        font: button6.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  operationwindow.dark 
                    }
                    onClicked:  if(operationwindow.isEnabled== true){
                        operationwindow.input+=("0")}
                        else{
                            operationwindow.input+=("6")
                        }
                }    
                  Button {
                    id: button7
                    text: if(operationwindow.isEnabled == true){
                        ("(")
                        }
                    else{
                        ("7")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button7.text
                        color: operationwindow.light 
                        font: button7.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  operationwindow.dark 
                    }
                    onClicked:  if(operationwindow.isEnabled== true){
                        operationwindow.input+=("(")}
                        else{
                            operationwindow.input+=("7")
                        }
                }
                 Button {
                    id: button8
                    text: if(operationwindow.isEnabled == true){
                        (")")
                        }
                    else{
                        ("8")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button8.text
                        color: operationwindow.light 
                        font: button8.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: operationwindow.dark 
                    }
                    onClicked:  if(operationwindow.isEnabled== true){
                        operationwindow.input+=(")")}
                        else{
                            operationwindow.input+=("8")
                        }
                }      
                Button {
                    id: button9
                    text: ("9")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button9.text
                        color:  operationwindow.light 
                        font: button9.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  operationwindow.dark 
                    }
                    onClicked: operationwindow.input+=("9")
                }          
        }
    }

}