import QtQuick 2.0

Rectangle {
    id: handle
    width: 100; height: 100
    color: "red"

    MouseArea {
        anchors.fill: parent
        onClicked: {
        }
        onPressedChanged: {
            pressed ? console.log("Button pressed!")
                    : console.log("Button released!")
        }
    }
}
