import QtQuick 2.7

Page1Form {
    button1.onClicked: {
        color = colors.get(comboBox1.currentIndex).color
    }
}
