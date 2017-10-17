import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 400
    height: 500
    minimumWidth: 400
    minimumHeight: 500
//    maximumWidth: width
//    maximumHeight: height
    title: qsTr("Hello World") + qmlTranslator.emptyString


    Page1 {
        anchors.fill: parent
    }

    Connections {
        target: qmlTranslator
        onLanguageChanged: {
            console.log("QML language chaged")
            mainWindow.title = qsTr("Hello World")
        }
    }
}
