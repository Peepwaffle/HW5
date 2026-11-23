import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
ApplicationWindow {
   
    id: windowTests
    width: 800
    height: 750
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Test Results")
    property string results : "";
    


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
            id: rectangle2
            color: windowTests.light
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                Text{
                    id: resultsText;
                    text: windowTests.results;
                }

               

                

                     
                    
                    
                
                
             
              
            }
        }
    }

}


