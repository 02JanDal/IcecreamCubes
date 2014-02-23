import QtQuick 2.0

Rectangle {
    height: 32
    width: parent.width
    radius: 1
    border.color: "lightblue"
    border.width: 1
    color: "aquamarine"

    property string text: ""
    signal clicked

    Text {
        anchors.centerIn: parent
        text: parent.text
        color: parent.border.color
        font.pointSize: 16
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
