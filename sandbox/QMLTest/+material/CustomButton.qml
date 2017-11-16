import QtQuick 2.6
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1

Button {
    id: control

    Material.theme: Material.Dark

    background: Rectangle {
        implicitWidth: 48
        implicitHeight: 48
        color: Material.accentColor
        radius: width / 2

        layer.enabled: control.enabled
        layer.effect: DropShadow {
            verticalOffset: 1
            color: Material.dropShadowColor
            samples: control.pressed ? 50 : 10
            spread: 0.9
        }
    }
}
