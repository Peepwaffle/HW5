import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import QML
import QtQuick.Dialogs
ApplicationWindow {
    id: filewindow
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("File reader")
    property bool lightMode: Application.styleHints.colorScheme === Qt.Light
    property string fileName : ""
 
   
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
            color:  filewindow.reallyLight 
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                Label {
                    id: text1
                    color: filewindow.dark 
                    font.pixelSize: 120
                    fontSizeMode: Text.Fit
                    text: qsTr("Enter in the path name of your file")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                   Label {
                    id: textNotFoundFile
                    color: filewindow.dark 
                    font.pixelSize: 120
                    fontSizeMode: Text.Fit
                    text: qsTr("Error: Selected file cannot be accessed")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    visible: false
                }
            }
        }

        Rectangle {
            id: rectangle2
            color: filewindow.light 
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Text{
                    id : textFirstLine
                    text : ""
                     Layout.alignment: Qt.AlignHCenter | Qt.AlignCenter
                }
                 Text{
                    id : textSecondLine
                    text : ""
                     Layout.alignment: Qt.AlignHCenter | Qt.AlignCenter
                }
             TextField {
                placeholderText: qsTr("File path")
                   Layout.alignment: Qt.AlignHCenter | Qt.AlignCenter
                onAccepted:{
                    if(text.length< 1){
                        textFirstLine.text = "You didn't enter in a file, please try again."
                    }
                    else{
                    filewindow.fileName = text
                  textFirstLine.text = "You selected " + text + "."
                  textSecondLine.text= "Is that correct?"
                  }
                }
                }
     
      
    
              Button {
                    id: buttonYes
                    text: ("Yes")
                    visible: { 
                        if(filewindow.fileName.length!= 0){
                            true;
                        }
                        else{
                            false;
                        }
                    }                                      
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                    contentItem: Text {
                        text: buttonYes.text
                        color:  filewindow.light
                        font: buttonYes.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  filewindow.dark 
                    }

                      onClicked: {
                      
                       
                      if(Calculator.OpenUpFile(filewindow.fileName)=== 2){
                        textNotFoundFile.visible = true;

                      }
                      else{
                        
                    Par.SetQMLParseFlag("f");
                        const component = Qt.createComponent("FileResults.qml");
                  var windowResult = component.createObject()
                  var result = Par.CanReadThroughFile(filewindow.fileName);
                  if(result!= 0){
                    windowResult.boolEnd = true;
                    windowResult.endedFile = result;

                  }
                  windowResult.fileName= filewindow.fileName;
                
                     windowResult.show(); 
               filewindow.hide();
                      }
                    
                        
                      }
                    
                    
                }
                 Button {
                    id: buttonNo
                    text: ("No")
                  
                    visible: { 
                        if(filewindow.fileName.length!= 0){
                            true
                        }
                        else{
                            false
                        }

                    }                                      
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                    contentItem: Text {
                        text: buttonNo.text
                        color:  filewindow.light
                        font: buttonNo.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  filewindow.dark 
                    }

                      onClicked: {
                        filewindow.fileName = ""
               
                      }
                    
                    
                }
               
            }
        }
    }

}
