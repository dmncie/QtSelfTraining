import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }

            Column {
                CustomButton { text: "A"; width: 50; height: 50 }
                CustomButton { text: "B"; x: 50; width: 100; height: 50; }
                CustomButton { text: "C"; width: 50; height: 50;}
            }

            Text {
                onFontChanged: console.log("font changed")

                Text { id: otherText }

                focus: true

                Keys.onDigit1Pressed: font.pixelSize += 1
                Keys.onDigit2Pressed: font.bold = !font.bold
                Keys.onDigit3Pressed: font = otherText.font
            }
        }

        Page3 {}

        Page {
            ColumnLayout {
                anchors.centerIn: parent
                Label {
                    text: qsTr("Fourth page")
                }

                SquareButton {
                    onActivated: console.log("Activated at " + xPosition + "," + yPosition)
                }
                SquareButton {
                    onActivated: console.log("Activated at " + xPosition + "," + yPosition)
                }
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
        TabButton {
            text: qsTr("Third")
        }
        TabButton {
            text: qsTr("Fourth")
        }
    }
}
