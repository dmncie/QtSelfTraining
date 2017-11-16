import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.XmlListModel 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property bool loading: feedModel.status === XmlListModel.Loading

    onLoadingChanged: {
        if (feedModel.status == XmlListModel.Ready)
            list.positionViewAtBeginning()
    }

    XmlListModel {
        id: feedModel

        source: "http://mangastream.com/rss"
        query: "/rss/channel/item"

        XmlRole { name: "title"; query: "title/string()" }
        XmlRole { name: "link"; query: "link/string()" }
        XmlRole { name: "description"; query: "description/string()" }
        XmlRole { name: "pubDate"; query: "pubDate/string()" }
        //        XmlRole { name: "image"; query: "image/string()" }
    }

    Page {
        anchors.fill: parent

        header: BusyIndicator {
            id: busy
            visible: window.loading
            anchors.horizontalCenter: parent.horizontalCenter
            opacity: 0.5
        }

        Flickable {
            id: flickable
            flickableDirection: Flickable.VerticalFlick
            anchors.fill: parent
            clip: true
            leftMargin: 20
            opacity: busy.visible ? 0.5 : 1

            ListView {
                id: list
                anchors.fill: parent
                model: feedModel
                delegate: FeedDelegate {}
            }

            onMovementEnded: {
                if (atYBeginning) {
                    feedModel.reload()
                }
            }
            ScrollBar.vertical: ScrollBar {}
        }
    }
}
