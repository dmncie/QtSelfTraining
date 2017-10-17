import QtQuick 2.9
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    width: 400
    height: 500

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
                text: qsTr("Name:") + qmlTranslator.emptyString
            }

            TextField {
                id: textField
                text: qsTr("Text Field") + qmlTranslator.emptyString
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignLeft
            }

            Label {
                id: label1
                text: qsTr("Last Name:") + qmlTranslator.emptyString
            }

            TextField {
                id: textField1
                text: qsTr("Text Field") + qmlTranslator.emptyString
                Layout.fillWidth: true
            }

            Label {
                id: label2
                text: qsTr("Age:") + qmlTranslator.emptyString
            }

            SpinBox {
                id: spinBox
                editable: true
            }

            Label {
                id: label3
                text: qsTr("Country:") + qmlTranslator.emptyString
            }

            ComboBox {
                id: comboBox
                currentIndex: 0
                Layout.fillWidth: true
                model: ListModel {
                    id: cbModel
                }

                ListModel {
                    id: cbItems
                    ListElement {
                        text: QT_TR_NOOP("Poland")
                        code: "pl"
                    }
                    ListElement {
                        text: QT_TR_NOOP("England")
                        code: "en"
                    }
                    ListElement {
                        text: QT_TR_NOOP("Germany")
                        code: "de"
                    }
                }

                Component.onCompleted: {
                    for (var i = 0; i < cbItems.count; i++) {
                        cbModel.append({
                                           text: qsTr(cbItems.get(i).text)
                                       })
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
                    text: qsTr("swimming") + qmlTranslator.emptyString
                }

                CheckBox {
                    id: checkBox6
                    text: qsTr("running") + qmlTranslator.emptyString
                }

                CheckBox {
                    id: checkBox5
                    text: qsTr("heavy weight lifting") + qmlTranslator.emptyString
                }

                CheckBox {
                    id: checkBox4
                    text: qsTr("skating") + qmlTranslator.emptyString
                }

                CheckBox {
                    id: checkBox3
                    text: qsTr("cricket") + qmlTranslator.emptyString
                }

                CheckBox {
                    id: checkBox2
                    text: qsTr("hockey") + qmlTranslator.emptyString
                }

                CheckBox {
                    id: checkBox1
                    text: qsTr("basketball") + qmlTranslator.emptyString
                }

                CheckBox {
                    id: checkBox
                    text: qsTr("football") + qmlTranslator.emptyString
                }
            }
        }

        Item {
            id: spacer
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        RowLayout {
            id: rowLayout
            Layout.alignment: Qt.AlignRight | Qt.AlignBottom
            Layout.fillWidth: true

            Button {
                id: button
                text: qsTr("OK") + qmlTranslator.emptyString
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            }

            Button {
                id: button1
                text: qsTr("Cancel") + qmlTranslator.emptyString
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            }
        }
    }

    Connections {
        target: button1
        onClicked: close()
    }

    Connections {
        target: button
        onClicked: close()
    }

    Connections {
        target: comboBox
        onCurrentIndexChanged: {
            qmlTranslator.setLanugage(cbItems.get(comboBox.currentIndex).code)
        }
    }

    Connections {
        target: qmlTranslator
        onLanguageChanged: {
            for (var i = 0; i < cbItems.count; i++) {
                cbModel.get(i).text = qsTr(cbItems.get(i).text)
            }
        }
    }
}
