import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Page {
        anchors.fill: parent

        Rectangle {
            id: outerRect
            anchors.centerIn: parent
            width: parent.width/2
            height: parent.height/2
            color: "lightGray"
            readonly property int maxMargin: 40
            readonly property int minMargin: 50
            property int innerRectMargin: maxMargin

            function getArea() {
                return width * height
            }

            Text {
                id: text
                font.bold: true
                font.pixelSize: 18
                text: outerRect.getArea() + " px"
            }

            Rectangle {
                id: innerRect
                anchors.centerIn: parent
                width: parent.width - parent.innerRectMargin
                height: parent.height - parent.innerRectMargin
                color: "gray"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Outer rect clicked: (" + mouseX + ", " + mouseY + ")")
                }

                onPressedChanged: {
                    if (pressed) {
                        parent.innerRectMargin = parent.minMargin
                    } else {
                        parent.innerRectMargin = parent.maxMargin
                    }
                }
            }
        }
    }
}
