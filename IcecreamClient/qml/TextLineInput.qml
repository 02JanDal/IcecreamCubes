import QtQuick 2.0

Rectangle {
    height: 32
    width: parent.width
    radius: 1
    border.color: "lightblue"
    border.width: 1
    color: "aquamarine"

    property string text: input.text
    function clear()
    {
        input.text = ""
    }
    function focus()
    {
        input.focus = true
    }

    TextInput {
        id: input
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 2
        font.pointSize: 14
        color: parent.border.color
    }
}
