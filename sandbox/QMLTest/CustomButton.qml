import QtQuick 2.6
import QtQuick.Controls 2.1

Button {
    id: control

    background: Rectangle {
        radius: width / 2
        implicitWidth: 36
        implicitHeight: 36
        color: control.pressed ? "#ccc" : "#eee"
    }

    onClicked: {
        onClicked: console.log("Button clicked!")
    }
}
