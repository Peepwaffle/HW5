import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import HW5




ApplicationWindow {
    id: terminalwindow
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Terminal")
    
   property bool isEnabled: false
   property string input : ""
   property int opCounter : 0;
   property string possibleOps : "+-*/%";
   

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
            color: terminalwindow.reallyLight 
            Layout.fillHeight: true
            Layout.fillWidth: true
            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Label {
                    id: text1
                    color: terminalwindow.dark
                    font.pixelSize: 100
                    fontSizeMode: Text.Fit
                    text: qsTr("Enter the equation you would like to calculate")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                 Label {
                    id: textNote
                    color: terminalwindow.dark
                    font.pixelSize: 100
                    fontSizeMode: Text.Fit
                    text: qsTr("For negative numbers, delete the space after \"-\"")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                 Label{
                    id :textEmpty
                    color: terminalwindow.dark
                    font.pixelSize: 80
                    fontSizeMode: Text.Fit
                    text: ("No equation or number submitted, try again")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    visible:false
                    
                }
                 Label{
                    id :textMoreOps
                    color: terminalwindow.dark
                    font.pixelSize: 80
                    fontSizeMode: Text.Fit
                    text: ("More than one operator used, try again")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    visible:false
                    
                }
                  Label{
                    id :textNoSecond
                    color: terminalwindow.dark
                    font.pixelSize: 80
                    fontSizeMode: Text.Fit
                    text: ("No second number selected, try again")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    visible:false
                    
                }
                 Label {
                    id: textSwitch
                    color: terminalwindow.dark
                    font.pixelSize: 100
                    fontSizeMode: Text.Fit
                    text: qsTr("Switch allows you to switch to 0 and operators")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
              

                Label {
                    id: textInput
                    color: terminalwindow.dark
                    font.pixelSize: 25
                    fontSizeMode: Text.Fit
                    text: qsTr("Current input: "+ terminalwindow.input)
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
                color:  terminalwindow.light 
                font: buttonEnter.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    implicitWidth: 120
                    implicitHeight: 36
                    radius: 8
                    color: terminalwindow.dark 
                }    
                onClicked:{
                if(terminalwindow.input.length < 1){
                    textEmpty.visible = true
                }
                else if(terminalwindow.input.endsWith(" ")){
                    textNoSecond.visible = true;
                }
                else if(terminalwindow.opCounter > 1){
                    textMoreOps.visible = true;
                }
                else{
                     const last = terminalwindow.input.charAt(terminalwindow.input.length-1);
                     if(last === " "){
                      terminalwindow.input  = terminalwindow.input.substring(0, terminalwindow.input.length - 1);
                     }
                  const component = Qt.createComponent("TerminalResults.qml")
                  const windowResult = component.createObject()
                  windowResult.input= terminalwindow.input;
                  if(terminalwindow.opCounter === 0){
                    TElement.Value(terminalwindow.input.toString());
                    var Value = TElement.Value();
                    windowResult.result = Value;

                  }
                  else{
                      Help.CreateString(terminalwindow.input);
                 var Value = Help.Value();
                     windowResult.result = Value;
                  }
                     windowResult.show();
                  
                     
                terminalwindow.hide();
                }
                }           
                }
                Button {
                    id: buttonDelete
                    text: ("Delete")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: buttonDelete.text
                        color:  terminalwindow.light 
                        font: buttonDelete.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }
                    onClicked:{
                        var last = terminalwindow.input.charAt(terminalwindow.input.length-1);
                    terminalwindow.input  = terminalwindow.input.substring(0, terminalwindow.input.length - 1);
                       if(terminalwindow.possibleOps.includes(last.toString())){ 
                       terminalwindow.opCounter-=1;
                    } 
                    else if(terminalwindow.input.charAt(terminalwindow.input.length-1) === "-" ){
                        terminalwindow.opCounter-=1;
                    }
                    }
                }
                 Button {
                    id: buttonSwitch
                 text: ("Switch")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: buttonSwitch.text
                        color: terminalwindow.light 
                        font: buttonSwitch.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }
                    onClicked:
                    terminalwindow.isEnabled = !terminalwindow.isEnabled
                }
                Button {
                    id: button1
                    text: 
                    if(terminalwindow.isEnabled == true){
                        ("+")
                        }
                    else{
                        ("1")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button1.text
                        color: terminalwindow.light
                        font: button1.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }

                    onClicked: 
                    if(terminalwindow.isEnabled== true){
                        terminalwindow.input+=(" + ")
                        terminalwindow.opCounter += 1;
                        }
                        else{
                            terminalwindow.input+=("1")
                        }
                }

                Button {
                    id: button2
                    text:  
                    if(terminalwindow.isEnabled == true){
                        ("-")
                        }
                    else{
                        ("2")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button2.text
                        color:  terminalwindow.light 
                        font: button2.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }

                    onClicked:  if(terminalwindow.isEnabled== true){
                        terminalwindow.input+=(" - ");
                        terminalwindow.opCounter +=1;
                        
                        }
                        else{
                            terminalwindow.input+=("2");
                        }
                }
                 Button {
                    id: button3
                    text: 
                     if(terminalwindow.isEnabled == true){
                        ("*")
                        }
                    else{
                        ("3")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button3.text
                        color:  terminalwindow.light 
                        font: button3.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }

                    onClicked:  
                    if(terminalwindow.isEnabled== true){
                        terminalwindow.input+=(" * ")
                        terminalwindow.opCounter+=1;
                        }
                        else{
                            terminalwindow.input+=("3")
                        }
                }
                 Button {
                    id: button4
                    text: 
                     if(terminalwindow.isEnabled == true){
                        ("/")
                        }
                    else{
                        ("4")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button4.text
                        color:  terminalwindow.light 
                        font: button4.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }
                    onClicked:  
                    if(terminalwindow.isEnabled== true){
                        terminalwindow.input+=(" / ")
                        terminalwindow.opCounter+=1;}
                        else{
                            terminalwindow.input+=("4")
                        }
                }
            Button {
                    id: button5
                    text:  if(terminalwindow.isEnabled == true){
                        ("%")
                        }
                    else{
                        ("5")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button5.text
                        color: terminalwindow.light 
                        font: button5.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }
                    onClicked: 
                     if(terminalwindow.isEnabled== true){
                        terminalwindow.input+=(" % ")
                        terminalwindow.opCounter+=1;
                      
                        }
                        else{
                            terminalwindow.input+=("5")
                        }
                }
              Button {
                    id: button6
                    text:  
                    if(terminalwindow.isEnabled == true){
                        ("0")
                        }
                    else{
                        ("6")
                        }
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button6.text
                        color: terminalwindow.light 
                        font: button6.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }
                    onClicked: 
                     if(terminalwindow.isEnabled== true){
                        terminalwindow.input+=("0")
                        }
                        else{
                            terminalwindow.input+=("6")
                        }
                   
                }    
                  Button {
                    id: button7
                    text: ("7")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button7.text
                        color:  terminalwindow.light 
                        font: button7.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  terminalwindow.dark 
                    }
                    onClicked: terminalwindow.input+=("7")
                }
                 Button {
                    id: button8
                    text: ("8")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button8.text
                        color: terminalwindow.light 
                        font: button8.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  terminalwindow.dark 
                    }
                    onClicked: terminalwindow.input+=("8")
                }      
                Button {
                    id: button9
                    text: ("9")
                    Layout.bottomMargin: 16
                    contentItem: Text {
                        text: button9.text
                        color:  terminalwindow.light 
                        font: button9.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark 
                    }
                    onClicked: terminalwindow.input+=("9")
                }          
        }
    }

}
