import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    width: 400
    height: 600

    property alias gridLayout: gridLayout
    property alias rowLayout: rowLayout
    property alias groupBox: groupBox

    ColumnLayout {
        id: columnLayout
        clip: false
        anchors.rightMargin: 15
        anchors.leftMargin: 15
        anchors.bottomMargin: 15
        anchors.topMargin: 15
        Layout.minimumWidth: 300
        spacing: 5
        anchors.fill: parent

        GridLayout {
            id: gridLayout
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            rows: 4
            columns: 2
            width: parent.width
            Layout.fillWidth: true

            Label {
                id: label
                text: qsTr("Name:")
            }

            TextField {
                id: textField
                text: qsTr("Text Field")
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignLeft
            }

            Label {
                id: label1
                text: qsTr("Last Name:")
            }

            TextField {
                id: textField1
                text: qsTr("Text Field")
                Layout.fillWidth: true
            }

            Label {
                id: label2
                text: qsTr("Age:")
            }

            SpinBox {
                id: spinBox
            }

            Label {
                id: label3
                text: qsTr("Country:")
            }

            ComboBox {
                id: comboBox
                currentIndex: 0
                textRole: qsTr("text")
                model: ListModel {
                    id: cbItems
                    ListElement {
                        text: qsTr("Poland")
                        code: "pl"
                    }
                    ListElement {
                        text: qsTr("England")
                        code: "eng"
                    }
                    ListElement {
                        text: qsTr("Germany")
                        code: "de"
                    }
                }
            }
        }

        GroupBox {
            id: groupBox
            Layout.minimumWidth: 300
            Layout.columnSpan: 50
            Layout.fillHeight: false
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            title: qsTr("Sports:")

            GridLayout {
                id: gridLayout1
                rowSpacing: 6
                columnSpacing: 40
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                columns: 2

                CheckBox {
                    id: checkBox7
                    text: qsTr("swimming")
                }

                CheckBox {
                    id: checkBox6
                    text: qsTr("running")
                }

                CheckBox {
                    id: checkBox5
                    text: qsTr("heavy weight lifting")
                }

                CheckBox {
                    id: checkBox4
                    text: qsTr("skating")
                }

                CheckBox {
                    id: checkBox3
                    text: qsTr("cricket")
                }

                CheckBox {
                    id: checkBox2
                    text: qsTr("hockey")
                }

                CheckBox {
                    id: checkBox1
                    text: qsTr("basketball")
                }

                CheckBox {
                    id: checkBox
                    text: qsTr("football")
                }
            }
        }

        Item {
            id: spacer
            width: 200
            height: 200
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        RowLayout {
            id: rowLayout
            Layout.alignment: Qt.AlignRight | Qt.AlignBottom
            Layout.fillWidth: true

            Button {
                id: button
                text: qsTr("OK")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            }

            Button {
                id: button1
                text: qsTr("Cancel")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            }
        }
    }

    //    Connections {
    //        target: button1
    //        onClicked: close()
    //    }

    //    Connections {
    //        target: button
    //        onClicked: close()
    //    }
}
