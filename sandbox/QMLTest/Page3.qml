import QtQuick 2.0

Item {
    Column {
        anchors.centerIn: parent
        MyButton { width: 50; height: 50 }
        MyButton { x: 50; width: 100; height: 50; color: "blue" }
        MyButton { width: 50; height: 50; radius: 8 }
    }

    Rectangle {
        anchors.left: parent.left
        width: 200
        height: parent.height/2
        color: "red"

        Rectangle {
            width: 100
            height: parent.height/2
            color: "blue"
        }
    }

    Rectangle {
        anchors.right: parent.right
        width: parent.width/4
        height: parent.height/4
        color: "green"

        Rectangle {
            anchors.right: parent.right
            width: {
                if (parent.width > 200)
                    return parent.width / 2
                else
                    return parent.width / 4
            }
            height: parent.height > 100 ? parent.height : parent.height/2
            color: "red"
        }
    }

    Rectangle {
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 100
        height: width * 2
        color: "blue"
        id: rect1

        MouseArea {
            id: mouseArea1
            anchors.fill: parent
            onClicked: parent.width = parent.width*1.05
        }

        Connections {
            target: mouseArea1
            onClicked: {
                rect1.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
            }
        }
    }

    Rectangle {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        id: rect
        width: 100; height: 100
        color:  Qt.rgba(Math.random(), Math.random(), Math.random(), 1)

        MouseArea {
            anchors.fill: parent
            onClicked: {
                rect.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);

                // access 'mouse' parameter
                console.log("Clicked mouse at", mouse.x, mouse.y)
            }
            onPressedChanged: {
                console.log("Mouse area is pressed?", pressed)
            }
        }

        Component.onCompleted: {
            console.log("The rectangle's color is", color)
        }
    }
}
