import QtQuick 2.8

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    Item {
        id: myItem
        width: 200
        height: 200

        Rectangle {
            id: myRect
            width: 100
            height: 100
            color: "red"
        }

        states: [
            State {
                name: "moved"
                PropertyChanges {
                    target: myRect
                    x: 50
                    y: 50
                }
            }
        ]

        transitions: [
            Transition {
                NumberAnimation {
                    properties: "x,y"
                    duration: 500
                }
            }
        ]

        MouseArea {
            anchors.fill: parent
            onClicked: myItem.state = 'moved'
        }
    }
}
