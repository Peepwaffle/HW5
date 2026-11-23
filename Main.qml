import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
  




 

ApplicationWindow {
   
    id: windowMain
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("MainMenu")
    


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
            color:  windowMain.reallyLight 
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                Label {
                    id: text1
                    color:  windowMain.dark 
                    font.pixelSize: 120
                    fontSizeMode: Text.Fit
                    text: qsTr("Select a function to perform")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }

        Rectangle {
            id: rectangle2
            color: windowMain.light
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                Button {
                    id: buttonFile
                    text:  ("Read a file")
                                      
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                    contentItem: Text {
                        text: buttonFile.text
                        color:  windowMain.light
                        font: buttonFile.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color:  windowMain.dark 
                    }

                      onClicked: {
          
                      const component = Qt.createComponent("File.qml");
                const window2    = component.createObject()
                window2.show()
              
                windowMain.hide()
                      }
                    
                    
                }
                Button {
                    id: buttonTest
                    text: ("Run tests")
                       
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                    contentItem: Text {
                        text: buttonTest.text
                        color: windowMain.light 
                        font: buttonTest.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: windowMain.dark 
                    }

                      onClicked: {
                      const component = Qt.createComponent("Testing.qml")
                const window2    = component.createObject();
             window2.results = Tester.RunTests();

                window2.show();   
                windowMain.hide();
                      }
                
                }
                 Button {
                    id: buttonElement
                    text: ("Calculate using 2 numbers")
                       
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                    contentItem: Text {
                        text: buttonElement.text
                        color: windowMain.light 
                        font: buttonElement.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: windowMain.dark 
                    }

                      onClicked: {
                      const component = Qt.createComponent("Terminal.qml")
                const window2    = component.createObject()
                window2.show()
            
               
                windowMain.hide()
                      }
                
                }
                Button {
                    id: buttonTerminal
                    text: ("Calculate using more than 2 numbers")
                       
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                    contentItem: Text {
                        text: buttonTerminal.text
                        color:  windowMain.light 
                        font: buttonTerminal.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: windowMain.dark 
                    }

                      onClicked: {
                        
                      var component = Qt.createComponent("Operations.qml")
                      var window2 = component.createObject()
                window2.show()
                windowMain.hide()
                      }
                    
                    
                }
            }
        }
    }

}

