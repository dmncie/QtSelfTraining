import QtQuick 2.7
import QtQuick.Controls 2.2
import "ColorGenerator.js" as ColorGenerator

Item {
    CustomButton {
        anchors.left: parent.left
        anchors.top: parent.top
    }

    CustomButton {
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    CustomButton {
        anchors.left: parent.left
        anchors.bottom: parent.bottom
    }

    CustomButton {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
    }

    CustomButton {
        anchors.right: parent.right
        anchors.top: parent.top
    }

    CustomButton {
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }

    CustomButton {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    CustomButton {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
    }

    CustomButton2 {
        anchors.centerIn: parent
        onClicked: color = ColorGenerator.getColor()
    }
}
