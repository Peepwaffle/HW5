import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic



ApplicationWindow {
    id: terminalwindow
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Terminal")
    property bool lightMode: Application.styleHints.colorScheme === Qt.Light
    property int counter : 0
  


    
    property string input : ""
    property color reallyDark: "#1f1f1f"
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
            color: terminalwindow.lightMode ? terminalwindow.reallyLight : terminalwindow.reallyDark
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

        Rectangle {
            id: rectangle2
            color: terminalwindow.lightMode ? terminalwindow.light : terminalwindow.dark
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Button {
                    id: buttonshift
                    text: terminalwindow.lightMode ? qsTr("\u263D  Dark mode")
                                           : qsTr("\u263C  Light mode")
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft

                    contentItem: Text {
                        text: buttonshift.text
                        color: terminalwindow.lightMode ? terminalwindow.light : terminalwindow.dark
                        font: buttonshift.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.lightMode ? terminalwindow.dark : terminalwindow.light
                    }

                    onClicked: terminalwindow.lightMode = !terminalwindow.lightMode
                }
                 Button {
                    id: buttonDelete
                    text:  qsTr("Delete")
                                           
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignTop | Qt.AlignRight

                    contentItem: Text {
                        text: buttonDelete.text
                        color: terminalwindow.lightMode ? terminalwindow.light : terminalwindow.dark
                        font: buttonDelete.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.lightMode ? terminalwindow.dark : terminalwindow.light
                    }

                  // onClicked: terminalwindow.input = terminalwindow.input.substring(0, terminalwindow.input.length()-2)
                }
                Button {
                    id: button1
                    text: qsTr("1")
                                        
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                    contentItem: Text {
                        text: button1.text
                        color:  terminalwindow.light
                        font: button1.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark
                    }

                    onClicked: terminalwindow.input += "1"
                }  
                Button {
                    id: button2
                    text: qsTr("2")
                                        
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft

                    contentItem: Text {
                        text: button2.text
                        color:  terminalwindow.light
                        font: button2.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark
                    }

                    onClicked: terminalwindow.input += "2"
                }
                 Button {
                    id: button3
                    text: qsTr("3")
                                        
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft

                    contentItem: Text {
                        text: button3.text
                        color:  terminalwindow.light
                        font: button3.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark
                    }

                    onClicked: terminalwindow.input += "3"
                }
                Button {
                    id: button4
                    text: qsTr("4")
                                        
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                    contentItem: Text {
                        text: button4.text
                        color:  terminalwindow.light
                        font: button4.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark
                    }

                    onClicked: terminalwindow.input += "4"
                } 
                Button {
                    id: button5
                    text: qsTr("5")
                                        
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignTop | Qt.AlignCenter

                    contentItem: Text {
                        text: button5.text
                        color:  terminalwindow.light
                        font: button5.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark
                    }

                    onClicked: terminalwindow.input += "5"
                }
                 Button {
                    id: button6
                    text: qsTr("6")
                                        
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignCenter | Qt.AlignTop

                    contentItem: Text {
                        text: button6.text
                        color:  terminalwindow.light
                        font: button6.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark
                    }

                    onClicked: terminalwindow.input += "6"
                }
                 Button {
                    id: buttonEnter
                    text: qsTr("Confirm input")
                                           
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignRight | Qt.AlignBottom

                    contentItem: Text {
                        text: buttonEnter.text
                        color:  terminalwindow.light
                        font: buttonEnter.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.dark
                    }

                    onClicked: terminalwindow.lightMode = !terminalwindow.lightMode
                }
            }
        }
    }

}
