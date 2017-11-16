import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 500
    height: 700
    title: qsTr("Hello World")

    ListModel {
        id: nameModel
        ListElement { name: "Alice"; team: "Crypto" }
        ListElement { name: "Bob"; team: "Crypto" }
        ListElement { name: "Jane"; team: "QA" }
        ListElement { name: "Victor"; team: "QA" }
        ListElement { name: "Wendy"; team: "Graphics" }
    }

    Component {
        id: nameDelegate
        Item{
            id: componentRectangle
            width: parent.width; height: 30;
            clip: true; smooth: true

            Text {
                text: name;
                font.pixelSize: 24
                anchors.left: parent.left
                anchors.leftMargin: 2
            }

            transitions: Transition {
                NumberAnimation { properties: "x"; duration: 200 }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    teamPlayersListView.currentIndex = index
                    console.log("click", index, mouse.x, mouse.y)
                }
            }

        }
    }

    // Define a highlight with customized movement between items.
    Component {
        id: highlightBar
        Rectangle {
            width: 200; height: 50
            color: 'lightblue'
            y: listView.currentItem.y;
            Behavior on y { SpringAnimation { spring: 2; damping: 0.1 } }
        }
    }

    ListView {
        id: teamPlayersListView
        anchors.fill: parent
        clip: true
        model: nameModel
        delegate: nameDelegate
        currentIndex: 0
        header: bannercomponent
        footer: Rectangle {
            width: parent.width; height: 30;
            gradient: clubcolors
        }
        focus: true
        highlight: highlightBar
        section {
            property: "team"
            criteria: ViewSection.FullString
            delegate: Rectangle {
                color: "#b0dfb0"
                width: parent.width
                height: childrenRect.height + 4
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 16
                    font.bold: true
                    text: section
                }
            }
        }
    }

    Component {     //instantiated when header is processed
        id: bannercomponent
        Rectangle {
            id: banner
            width: parent.width; height: 50
            gradient: clubcolors
            border {color: "#9EDDF2"; width: 2}
            Text {
                anchors.centerIn: parent
                text: "Club Members"
                font.pixelSize: 32
            }
        }
    }

    Gradient {
        id: clubcolors
        GradientStop { position: 0.0; color: "#8EE2FE"}
        GradientStop { position: 0.66; color: "#0ED2EE"}
    }
}
