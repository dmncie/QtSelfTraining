import QtQuick 2.0

Rectangle {
    width: 200
    height: 100
    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            console.log("color changed " + parent.color)
        }
    }
}
