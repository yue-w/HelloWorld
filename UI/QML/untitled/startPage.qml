import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import "jsPassData.js" as JSPassData

Window {

    id:startPage_id
    visible: true
    width: 800
    height: 600

    property int marginValue: 5

    Rectangle {
        id: startSecondPage_id
        anchors.left: parent.left

        anchors.margins: 20

        height: 40
        width:200

        color: "#53d769"
        border.color: Qt.lighter(color, 1.1)

        Text {
            id: textPage1_id
            anchors.centerIn: parent

            text: "Go"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {

                   JSPassData.start();

            }
        }

    }


    Text{
        anchors.left: numOfVar_input_id.left
        anchors.bottom: numOfVar_input_id.top
        text: "number of variable"
    }

    TextField {
        id: numOfVar_input_id
        x:80
        y:80
        width: 100.1; height: 40


    }


    Text{
        anchors.left: numOfInequalFunc_input_id.left
        anchors.bottom: numOfInequalFunc_input_id.top
        text: "number of inequality function"
    }

    TextField {
        id: numOfInequalFunc_input_id
        x:80
        y:150
        width: 100.1; height: 40


    }
}
