import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 800
    height: 600
    id:root

    ListModel {
        id: theModel_variableName


        ListElement{name:""; lowerBound:""; upperBound:"";initialValue:""; solution:""}
        ListElement{name:""; lowerBound:""; upperBound:"";initialValue:""; solution:""}

    }


    ////Button to add componenet
    Rectangle {
        id: addComponentButton
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: optimizeButton.top
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
                theModel_variableName.append({})

              //testCallCpp.test()
            }
        }

    }

    ////Button to excute Optimization
    Rectangle {
        id: optimizeButton
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20

        height: 40

        color: "#53d769"
        border.color: Qt.lighter(color, 1.1)

        Text {
            anchors.centerIn: parent

            text: "Optimize"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {


              cppDataToQml();
            }
        }

    }

    /////Rectangle that contains the variable name, upper and lower bound, and initial value.
    Rectangle{
        id:recListView
        width: 480
        height: 150
        border.width: 1
        anchors.left: parent.left

        ListView {
            id:listView_id
            anchors.fill: parent
            anchors.margins: 20
            clip: true
            model: theModel_variableName
            delegate: variableName
        }

    }

    /////Rectangle that contains object function
    Rectangle{
        id:rectangleObjFunc
        width: 480
        height: 150
        border.width: 1
         anchors.top: recListView.bottom
        anchors.left: parent.left
        //anchors.top: recListView.top


        Column{
            ////Object Function
            TextField{

                //anchors.left: parent.left
                //anchors.left: recListView.right
                x:10
                anchors.margins: 20
                //anchors.bottomMargin: 80
                //y:theModel_variableName.y+10
                id: objectFunction
                width: 200
                height: 25
                placeholderText: "Object function"
                 onEditingFinished:{

                     ////To do
                    }////onEditingFinished Finish

            }

        }

    }

    Rectangle{

        id:results
        width: 310
        height: 150
        border.width: 1
        anchors.right: parent.right

        Rectangle{
            id:objResult
            width: 310
            height: 100
            border.color: "black"
            border.width: 1
            anchors.leftMargin: 10
            Text {
                id: objResultTxt
                text: ""
            }

        }

    }

    /////input
    Rectangle{
        id:inputs
        border.width: 1
        anchors.top: rectangleObjFunc.bottom
        width: 480
        height: 100

        Row{
            id:rowMaxIterationTimes
            Text {
                y:inputs+4
                id: txtItetimes
                anchors.left: parent.left
                text: qsTr("Max iteration times")
            }

            TextField{
                id:maxIteInputTxt
                width: 100
                height: 25
                x:200
                ////anchors.left: txtItetimes.right +100
                placeholderText: "1000"
                 onEditingFinished:{
                     ////Todo
                   }////onEditingFinished Finish

            }

        }

        Row{
            id:rowAccuracy
            y:rowMaxIterationTimes.y+30
            Text {
                id: txtAccuracy
                anchors.left: parent.left
                text: qsTr("Accuracy")
            }

            TextField{
                id:inputAccuracy
                width: 100
                height: 25
                x:200
                //anchors.left: txtAccuracy.right
                placeholderText: "0.001"
                 onEditingFinished:{
                     ////Todo
                   }////onEditingFinished Finish

            }

        }



    }


    Component {
        id: variableName
        ////Input variable name, lower bound, upper bound...
        Row{
            ////TextField for the variable name start.
            TextField {
                id:textFieldVariable
                width: 100
                height: 25
                placeholderText: "Vairable Name"
                onEditingFinished:{
                //set the text of the textField to the ListElement's property.
                name = textFieldVariable.getText(0,20)

                //The following is an example of getting a certain ListElement by ID (3 in this example)
                nameText.text = theModel_variableName.get(3).name
           }////onEditingFinished Finish

        }////TextField for the variable name end.

            ////TextField for the lower bound.
            TextField {
                id:textFieldLowerBound
                width: 80
                height: 25
                placeholderText: "Lower bound"
                onEditingFinished:{

                   ////Add

                    //set the text of the textField to the ListElement.
                    lowerBound = textFieldLowerBound.getText(0,20)

                    //The following is an example of get a certain ListElement by ID (3 in this example)
                   // nameText2.text = theModel_variableName.get(1).lowerBound

                }////onEditingFinished Finish

        }////TextField for the lower bound Finish

            ////TextField for the upper bound.
            TextField {
                id:textFieldUpperBound
                width: 80
                height: 25
                placeholderText: "Upper bound"
                onEditingFinished:{

                   ////Add.
                    ////Us role "upperBound"

                }////onEditingFinished Finish

        }////TextField for the upper bound Finish

            ////TextField for the InitialValue.
            TextField {
                id:textFieldInitialValue
                width: 80
                height: 25
                placeholderText: "Initial Value"
                onEditingFinished:{

                   ////Add.
                    ////Us role "initialValue"

                }////onEditingFinished Finish

        }////TextField for the InitialValue Finish

            ////TextField for the Solution.
            TextField {
                id:textFieldSolution
                width: 80
                height: 25
                placeholderText: "Solution"
                readOnly:true
                onEditingFinished:{

                   ////Add.
                    ////Us role "solution"

                }////onEditingFinished Finish

        }////TextField for the upper solution Finish


     }////Row end



    }////Component Finish

        Text {
        anchors.right: parent.right
        id: nameText
       // property string a:  theModel_variableName.get(0).number
        //property string a:  theModel_variableName.get(0).target

    }

        Text {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        id: nameText2
        anchors.centerIn: parent.y
        //property string a:  theModel_variableName.get(0).number
        //property string a:  theModel_variableName.get(0).target
        //text: "AAAA"

    }


    function cppDataToQml(){

        var lowerBnds = [];
        for(var i = 0; i< theModel_variableName.count; i++){

            lowerBnds.push(theModel_variableName.get(i).lowerBound);
        }


        testCallCpp.setLowerBound(lowerBnds);
       var variablVecOpted =  testCallCpp.test(lowerBnds);

        objResultTxt.text= "Minimium object value: " + testCallCpp.getObjOptedValue();

        for(var i = 0; i< theModel_variableName.count; i++){
//            var c = theModel_variableName.count;
//             theModel_variableName.get(i);
//             nameText2.text +=theModel_variableName.get(i).lowerBound;
            var tem = theModel_variableName.get(i).solution;




        }

    }

}
