import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 20 + idSignal.width + 20 + idMethodCall.width + 220
    height: 120
    title: qsTr("Transmiter")

    Rectangle{
        id: idSignal
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 20
        }

        width: txtSendSignal.contentWidth + 10
        height: txtSendSignal.contentHeight + 10
        border.width: 1
        color: isPress ? 'red' : 'green'

        property bool isPress: false
        Text {
            id: txtSendSignal
            text: "Signal"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onPressed: {
                idSignal.isPress = true
            }
            onReleased: {
                idSignal.isPress = false
                Transmiter.sendSignalDbus(1)
            }
        }
    }

    Rectangle{
        id: idMethodCall
        anchors{
            verticalCenter: parent.verticalCenter
            left:idSignal.right
            leftMargin: 20
        }
        width: txtMethodCall.contentWidth + 10
        height: txtMethodCall.contentHeight + 10
        border.width: 1
        color: isPress ? 'red' : 'green'

        property bool isPress: false
        Text {
            id: txtMethodCall
            text: "Method Call"
            anchors.centerIn: parent
        }
        MouseArea{
            anchors.fill: parent
            onPressed: {
                idMethodCall.isPress = true
            }
            onReleased: {
                idMethodCall.isPress = false
                Transmiter.methodCallDbus(2)
            }
        }
    }
}
