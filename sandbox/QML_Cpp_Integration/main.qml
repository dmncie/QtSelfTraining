import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Page {
        anchors.fill: parent
        Label {
            text: msg.author
            anchors.centerIn: parent
        }

        Rectangle {
            width: 200
            height: 100
            anchors.bottom: parent.bottom
            color: "darkGrey"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    var result = msg.isOld(99)
                    console.log("Result of isOld(99) = ", result)
                    msg.response("My response to message")
                    msg.author = "Andrzej Sapkowski"
                }
            }
        }


        Component.onCompleted: {
            // Invokes setAuthor(...) method
            msg.author = "Ernest Hemingway"
        }

        Connections {
            target: msg
            onAuthorChanged: {
                console.log("Author has changed")
            }
        }
    }
}
