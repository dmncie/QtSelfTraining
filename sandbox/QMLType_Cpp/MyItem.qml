import QtQuick 2.0

Item {
    width: 100
    height: 100

    property int someNumber: 100

    Rectangle {
        anchors.fill: parent
        objectName: "rect"
    }
}
