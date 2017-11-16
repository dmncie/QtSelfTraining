import QtQuick 2.0

Rectangle {
    id: root
    signal activated(real xPosition, real yPosition)

    property int side: 100
    width: side; height: side
    color: "yellow"

    MouseArea {
        anchors.fill: parent
        onPressed: root.activated(mouse.x, mouse.y)
    }
}
