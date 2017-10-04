import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    property alias button1: button1
    property alias comboBox1: comboBox1
    property alias colors: colors

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        ComboBox {
            id: comboBox1
            x: 71
            y: 20
            width: 193
            height: 40
            textRole: "key"
            model: ListModel {
                id: colors
                ListElement {
                    key: "Green"
                    color: "green"
                }
                ListElement {
                    key: "Yellow"
                    color: "yellow"
                }
                ListElement {
                    key: "Blue"
                    color: "blue"
                }
            }
        }

        Button {
            id: button1
            text: qsTr("Change color")
        }
    }
}
