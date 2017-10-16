import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    property var colors: [
        Qt.rgba(Math.random(),Math.random(),Math.random(),1),
        Qt.rgba(Math.random(),Math.random(),Math.random(),1),
        Qt.rgba(Math.random(),Math.random(),Math.random(),1),
        Qt.rgba(Math.random(),Math.random(),Math.random(),1),
        Qt.rgba(Math.random(),Math.random(),Math.random(),1),
        Qt.rgba(Math.random(),Math.random(),Math.random(),1),
        Qt.rgba(Math.random(),Math.random(),Math.random(),1),
        Qt.rgba(Math.random(),Math.random(),Math.random(),1)
    ]

    CustomButton2 {
        id: b1
        color: colors[0]
        anchors.left: parent.left
        anchors.top: parent.top
        onClicked: rotateColors()
    }

    CustomButton2 {
        id: b2
        color: colors[1]
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        onClicked: rotateColors()
    }

    CustomButton2 {
        id: b3
        color: colors[2]
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        onClicked: rotateColors()
    }

    CustomButton2 {
        id: b4
        color: colors[3]
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        onClicked: rotateColors()
    }

    CustomButton2 {
        id: b5
        color: colors[4]
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onClicked: rotateColors()
    }

    CustomButton2 {
        id: b6
        color: colors[5]
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        onClicked: rotateColors()
    }

    CustomButton2 {
        id: b7
        color: colors[6]
        anchors.right: parent.right
        anchors.top: parent.top
        onClicked: rotateColors()
    }

    CustomButton2 {
        id: b8
        color: colors[7]
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        onClicked: rotateColors()
    }

    function rotateColors() {
        var temp = colors[0]
        colors[0] = colors[1]
        colors[1] = colors[2]
        colors[2] = colors[3]
        colors[3] = colors[4]
        colors[4] = colors[5]
        colors[5] = colors[6]
        colors[6] = colors[7]
        colors[7] = temp
        updateColors()
    }

    function updateColors() {
        b1.color = colors[0]
        b2.color = colors[1]
        b3.color = colors[2]
        b4.color = colors[3]
        b5.color = colors[4]
        b6.color = colors[5]
        b7.color = colors[6]
        b8.color = colors[7]
    }

    CustomButton2 {
        anchors.centerIn: parent
        onClicked: {
            color = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[0] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[1] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[2] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[3] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[4] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[5] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[6] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            colors[7] = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
            updateColors()
        }
    }
}
