import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic


ApplicationWindow {
    id: fileResultwindow
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("File Result")
    property bool lightMode: Application.styleHints.colorScheme === Qt.Light
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
            color: fileResultwindow.lightMode ? fileResultwindow.reallyLight : fileResultwindow.reallyDark
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                Label {
                    id: text1
                    color: fileResultwindow.lightMode ? fileResultwindow.dark : fileResultwindow.light
                    font.pixelSize: 120
                    fontSizeMode: Text.Fit
                    text: qsTr("Here are the results from your selected file:")
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
            color: fileResultwindow.lightMode ? fileResultwindow.light : fileResultwindow.dark
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                Button {
                    id: button1
                    text: fileResultwindow.lightMode ? qsTr("\u263D  Dark mode")
                                           : qsTr("\u263C  Light mode")
                    Layout.bottomMargin: 16
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                    contentItem: Text {
                        text: button1.text
                        color: fileResultwindow.lightMode ? fileResultwindow.light : fileResultwindow.dark
                        font: button1.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 36
                        radius: 8
                        color: fileResultwindow.lightMode ? fileResultwindow.dark : fileResultwindow.light
                    }

                    onClicked: fileResultwindow.lightMode = !fileResultwindow.lightMode
                }
            }
        }
    }

}