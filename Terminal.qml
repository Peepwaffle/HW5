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
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                    contentItem: Text {
                        text: buttonshift.text
                        color: terminalwindow.lightMode ? terminalwindow.light : terminalwindow.dark
                        font: buttonshift.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.lightMode ? terminalwindow.dark : terminalwindow.light
                    }

                    onClicked: terminalwindow.lightMode = !terminalwindow.lightMode
                }
                Button {
                    id: button1
                    text: terminalwindow.lightMode ? qsTr("\u263D  Dark mode")
                                           : qsTr("\u263C  Light mode")
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom

                    contentItem: Text {
                        text: button1.text
                        color: terminalwindow.lightMode ? terminalwindow.light : terminalwindow.dark
                        font: button1.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.lightMode ? terminalwindow.dark : terminalwindow.light
                    }

                    onClicked: terminalwindow.lightMode = !terminalwindow.lightMode
                }
                 Button {
                    id: buttonEnter
                    text: qsTr("Confirm input")
                                           
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignRight | Qt.AlignBottom

                    contentItem: Text {
                        text: buttonEnter.text
                        color:  terminalwindow.dark
                        font: buttonEnter.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: terminalwindow.light
                    }

                    onClicked: terminalwindow.lightMode = !terminalwindow.lightMode
                }
            }
        }
    }

}
