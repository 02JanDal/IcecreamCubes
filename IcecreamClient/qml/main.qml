import QtQuick 2.0

Rectangle {
    id: root
    color: "lightgreen"
    focus: true

    property bool chatVisible: false
    onChatVisibleChanged: {
        if (chatVisible)
        {
            chatInput.focus()
        }
    }

    Connections {
        target: RootWindow
        onIngameChanged: {
            if (!RootWindow.ingame)
            {
                root.chatVisible = false
            }
        }
    }

    Keys.onPressed: {
        if (!RootWindow.ingame)
        {
            return;
        }

        if (event.key === Qt.Key_T)
        {
            root.chatVisible = true
            event.accepted = true
        }
        else if (event.key === Qt.Key_Escape)
        {
            if (root.chatVisible)
            {
                root.chatVisible = false
            }
            else
            {
                RootWindow.stopPlaying()
            }
            event.accepted = true
        }
    }

    Column {
        anchors.centerIn: parent
        width: parent.width / 3
        spacing: 3
        visible: !RootWindow.ingame

        Button {
            text: qsTr("Play")
            onClicked: RootWindow.play()
        }
        Button {
            text: qsTr("Connect to server")
            onClicked: console.debug("Not implemented")
        }
        Button {
            text: qsTr("Quit")
            onClicked: Qt.quit()
        }
    }

    Rectangle {
        id: chatWindow
        visible: RootWindow.ingame && root.chatVisible
        anchors.bottom: parent.bottom
        anchors.margins: 10
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height / 2
        color: "transparent"

        Rectangle {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: chatInput.top
            anchors.bottomMargin: 10
            color: Qt.tint("aquamarine", "transparent")

            ListView {
                id: chatView
                anchors.fill: parent
                delegate: Text {
                    text: message
                }
                model: ListModel { id: chatModel }
                Connections {
                    target: RootWindow
                    onChat: chatModel.append({message:msg})
                }
            }
        }

        TextLineInput {
            id: chatInput
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: sendChatButton.left
            anchors.rightMargin: 10
            Keys.onPressed: {
                if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
                {
                    Network.sendChat(text)
                    clear()
                    event.accepted = true
                }
            }
        }

        Button {
            id: sendChatButton
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: 50
            text: "Send"
            onClicked: {
                Network.sendChat(chatInput.text)
                chatInput.clear()
            }
        }
    }
}
