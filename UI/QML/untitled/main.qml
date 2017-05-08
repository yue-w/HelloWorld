import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 600
    height: 800
    id:root



    ListModel {
        id: theModel


        ListElement{  }
        ListElement{  }

//        ListElement { number: 0 }
//        ListElement { number: 1 }
//        ListElement { number: 2 }
//        ListElement { number: 3 }


//        ListElement { number: 4 }
//        ListElement { number: 5 }
//        ListElement { number: 6 }
//        ListElement { number: 7 }
//        ListElement { number: 8 }
//        ListElement { number: 9 }
    }

    ////Button to add componenet
    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20

        height: 40

        color: "#53d769"
        border.color: Qt.lighter(color, 1.1)

        Text {
            anchors.centerIn: parent

            text: "Add a variable!"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                theModel.append({"number": ++parent.count});
            }
        }

        property int count: 9
    }

    ListView {
        anchors.fill: parent
        anchors.margins: 20
        anchors.bottomMargin: 80

        clip: true

        model: theModel

        //cellWidth: 45
        //cellHeight: 45

        delegate: variableName
    }

    Component {
        id: variableName

        Rectangle {
            id: wrapper
            width: 80
            height: 25
            //border.color: 'gray'
            //border.width: 1

//            TextEdit{
//                id:txtPlain
//                anchors.fill: parent
//                anchors.margins:4
//                property string placeholderText: "Variable Name"

//                //text: "Hello"
//                Text {
//                    text: txtPlain.placeholderText
//                    color: "#aaa"
//                    visible: !textEdit.text
//                }
//            }////End TextEdit


            TextField {
                width: 160
                height: 25
                placeholderText: "Vairable Name"
            }





        } ////Rectangle End



    }
}
