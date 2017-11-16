import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Transitions")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
                  anchors.fill: parent
                  id: page
                  mouseArea {
                            onClicked: stateGroup.state = ' '
                            }
        }

        StateGroup {
                  id: stateGroup
                  states: [
                      State {
                          name: "State1"

                          PropertyChanges {
                              target: page.icon
                              x: page.middleRightRect.x
                              y: page.middleRightRect.y
                          }
                      },
                      State {
                          name: "State2"

                          PropertyChanges {
                              target: page.icon
                              x: page.bottomLeftRect.x
                              y: page.bottomLeftRect.y
                          }
                      }
                  ]
        }

    }
}
