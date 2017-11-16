import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import com.company.messaging 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Page {
        anchors.fill: parent
        Message {
            id: firstMsg
            author: "Jan Kowalski"
            creationDate: new Date()
        }

        ColumnLayout {
            anchors.centerIn: parent

            Label {
                text: currentDateTime
            }

            Label {
                text: firstMsg.author
            }
        }
    }
}
