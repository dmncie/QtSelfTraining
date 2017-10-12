import QtQuick 2.0

Rectangle {
    width: 200
    height: 100
    color: Qt.rgba(0.5,0.5,0.5,1)

    signal clicked()

    MouseArea {
        id: mousearea
        anchors.fill: parent
    }

    Component.onCompleted: {
        mousearea.clicked.connect(clicked)
    }
}
