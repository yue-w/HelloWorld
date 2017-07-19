import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2

import "jsFunc.js" as JSFunc


Window {


    id: mainWindow_id
    visible: true
    width: 800
    height: 600
    property int marginValue: 5

    ////The total number of input for the matrix that contains
    ////The variable name, lower bound, upper bound and so on.
    property int inputMatrixTotal: 5

    ////The number of variable.
    property int numOfVariable:1

    ////The number of inequalitu functin
    property int numOfInequalFunc:1

    ////The number of the total input for the inequality function and corresponding
    ////Gradient. Each variable should have a gradeitn for each inequality function
    property int numOfInequalFuncAndGradInput: 6

    property string someParameter: "defaultParameter"

    Text {
        anchors.bottom: optimizeButton.top
        text: mainWindow_id.someParameter
    }

    ListModel {
        id: theModel_variableName


        ListElement{name:""; lowerBound:""; upperBound:"";initialValue:"";Gradient:""; solution:""}
        ListElement{name:""; lowerBound:""; upperBound:"";initialValue:"";Gradient:""; solution:""}

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
            id: exect_button_id
            anchors.centerIn: parent

            text: "Optimize"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {


             JSFunc.letsGo();

            }
        }

    }

    ////Button to add Inequality function and gradient
    Rectangle {
        id: addInequalityFuncAndGrad
        //anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: results.bottom
        anchors.margins: 20

        height: 40
        width:200

        color: "#53d769"
        border.color: Qt.lighter(color, 1.1)

        Text {
            anchors.centerIn: parent

            text: "Add Inequality Functions and Gradient"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                   JSFunc.addInequalityFuncAndGrad();

            }
        }

    }



    ////Headler, variable name, gradient and so on.
    Rectangle{
        id:recHeadlerAndInputs
        width: 480
        height: 220
        border.width: 1
        anchors.left: parent.left
        anchors.margins: marginValue

        ////Rectangle that contains the headler
        Rectangle{
            id:headler
            width: 473
            height: 25
            anchors.left: parent.left
            anchors.leftMargin: marginValue
            anchors.top: parent.top
            anchors.topMargin: marginValue
            //anchors.margins: 5
           // border.width: 1
            Row{

                Rectangle{

                    id:recName
                    width: 50
                    height: 25
                    //color:  "#f8306a"
                    border.color: black
                    //anchors.margins: marginValue
                    //anchors.leftMargin: marginValue
                    anchors.left: parent.left


                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: "Name"
                    }

                }
                Rectangle{

                    id:recLowBnd
                    width: 80
                    height: 25
                    //color:  "#f8306a"
                    border.color: black
                    //anchors.margins: marginValue
                    //anchors.leftMargin: marginValue
                    anchors.left: recName.right
                    anchors.leftMargin: marginValue

                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: "Lower bound"
                    }

                }

                Rectangle{

                    id:uperowBnd
                    width: 80
                    height: 25
                    //color:  "#f8306a"
                    border.color: black
                    //anchors.margins: marginValue
                    //anchors.leftMargin: marginValue
                    anchors.left: recLowBnd.right

                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: "Upper bound"
                    }

                }

                Rectangle{

                    id:upperBnd
                    width: 80
                    height: 25
                    //color:  "#f8306a"
                    border.color: black
                    //anchors.margins: marginValue
                    //anchors.leftMargin: marginValue
                    anchors.left: recLowBnd.right

                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: "Upper bound"
                    }

                }

                Rectangle{

                    id:gradHead
                    width: 80
                    height: 25
                    //color:  "#f8306a"
                    border.color: black
                    //anchors.margins: marginValue
                    //anchors.leftMargin: marginValue
                    anchors.left: upperBnd.right

                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: "Gradient"
                    }

                }

                Rectangle{

                    id:initialHead
                    width: 80
                    height: 25
                    //color:  "#f8306a"
                    border.color: black
                    //anchors.margins: marginValue
                    //anchors.leftMargin: marginValue
                    anchors.left: gradHead.right

                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: "Initial Value"
                    }

                }

                Rectangle{

                    id:resultHead
                    width: 80
                    height: 25
                    //color:  "#f8306a"
                    border.color: black
                    //anchors.margins: marginValue
                    //anchors.leftMargin: marginValue
                    anchors.left: initialHead.right

                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: "Results"
                    }

                }



            }



        }

        /////Rectangle that contains the variable name, upper and lower bound, and initial value.
        Rectangle{
            id:recListView
            width: 473
            height: 140
           // border.width: 1
            anchors.left: parent.left
            anchors.leftMargin: marginValue
            anchors.top: headler.bottom



            Rectangle{
                id: recVariableInput_id
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                width: 390
                border.color: black
                border.width: 1

                Grid{
                    id:userinput_id
                    columns: 5
                    columnSpacing  :10


                    Repeater{
                        id:userInputRepeater_id
                        model: inputMatrixTotal

                        TextField {
                            width: 50; height: 25
                            text:""

                        }

                    }

                }

            }

            Rectangle{
                id:recVarOptVal
                anchors.left: recVariableInput_id.right
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                border.color: black
                border.width: 1


//                    //Optimized value of the variables
//                    ListView{
//                        id: optimizedVarVal_id
//                        //anchors.left: parent.left
//                        anchors.fill: parent
//                        anchors.right: parent.right
//                        model:0
//                        delegate: component_optimizedVarVal_id

//                    }

                Column{
                    //anchors.fill: parent
                    Repeater{
                        id:optimizedVarVal_id
                        model:0
                        Rectangle {
                            id:recContainsResult
                            width: 50
                            height: 25
                            //anchors.centerIn: resultHead.Center
                            //anchors.right: recVarOptVal.right
                            //anchors.rightMargin: marginValue

                            color: ListView.isCurrentItem?"#157efb":"#53d769"
                            border.color: Qt.lighter(color, 1.1)
                            property string optRest: "Error"

                            Text {
                                anchors.centerIn: parent

                                font.pixelSize: 10

                                text: recContainsResult.optRest
                            }
                        }
//                            Text {
//                                anchors.left: recVarOptVal.left
//                                anchors.centerIn: parent

//                                font.pixelSize: 30

//                                text: "error"
//                            }

                    }
                }

            }

        }


        ////Button to add componenet
        Rectangle {
            id: addComponentButton
            anchors.left: parent.left
            //anchors.right: parent.right

            //anchors.bottom: optimizeButton.top
            anchors.top: recListView.bottom
            anchors.margins: marginValue

            height: 40
            width: parent.width/2- marginValue

            color: "#53d769"
            border.color: Qt.lighter(color, 1.1)

            Text {
                anchors.centerIn: parent

                text: "Add a variable"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {

                    //theModel_variableName.append({})
                    //JSFunc.setInequalityGrad();

                    JSFunc.addAVariable();


                }
            }

        }

        ////Button to remove a Component
        Rectangle {
            id: removeComponentButton
            anchors.left: addComponentButton.right
            anchors.right: parent.right
            //anchors.bottom: optimizeButton.top
            anchors.top: recListView.bottom
            anchors.margins: marginValue

            height: 40

            color: "#53d769"
            border.color: Qt.lighter(color, 1.1)

            Text {
                anchors.centerIn: parent

                text: "Remove a variable"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    theModel_variableName.remove(theModel_variableName.count-1,1);
                    JSFunc.setInequalityGrad();


                  //testCallCpp.test()
                }
            }

        }

    }


    /////Rectangle that contains object function and inequality function
    Rectangle{
        id:rectangleObjFunc
        width: 480
        height: 180
        border.width: 1
        anchors.top: recHeadlerAndInputs.bottom
        anchors.left: parent.left
        //anchors.top: recListView.top
        anchors.topMargin: marginValue
        anchors.margins: marginValue


        Column{
            ////Object Function
            TextField{
                id: objectFunction
                anchors.left: parent.left
                anchors.leftMargin: marginValue
                anchors.top: parent.top
                anchors.topMargin: marginValue
                selectByMouse: true
                width: 450
                height: 25
                placeholderText: "Object function"
                 onEditingFinished:{
                     ////To do

                   }////onEditingFinished Finish
            }

            ////Rectangle that contains the inequality function and corresponding grads
            Rectangle{
                id:recInequalityFuncs
                anchors.left: parent.left
                anchors.leftMargin: marginValue
                anchors.top: objectFunction.bottom
                anchors.topMargin: marginValue
                width: 460
                height: 130
                border.width: 1


                    Grid{
                        id:grid_ineqFun_grad
                        columns:numOfInequalFunc
                        columnSpacing  :10

                        Repeater{
                            id:repeaterInequalityFunAndGrad
                            model: numOfInequalFuncAndGradInput
                            TextField {
                                width: 100.1; height: 40
                                text:""

                            }

                        }

                    }
                }


        }

    }

    /////Rectangle that contains result
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
            anchors.leftMargin: marginValue

            Grid{
                id:outputGrid
                width:240
                height:80
                anchors.left: parent.left
                anchors.leftMargin: marginValue
                anchors.top: parent.top
                anchors.topMargin: marginValue
                rows:1
                columns:4
                spacing: 10

                Text {
                    id: minText
                    //anchors.left: parent.left
                    text: qsTr("Minimum value")

                }

                TextField{
                    id:minTxtField
                    width: 100
                    height: 25
                    placeholderText: " "
                    readOnly:true
                    selectByMouse: true
                    onEditingFinished:{
                         ////Todo
                       }////onEditingFinished Finish

                }

            }

        }

//        Rectangle{
//            width: 310
//            height: 100
//            anchors.top:results.bottom
//            border.width: 1

//            Grid{
//                columns: 2
//                Repeater{
//                    id:restRepeater
//                    model: 8
//                    TextField {
//                        width: 100.1; height: 40
//                        text:"hello"

//                    }




//                }

//            }


//        }

    }

    ///input- max iteration...
    Rectangle{
        id:inputs
        border.width: 1
        anchors.top: rectangleObjFunc.bottom
        width: 680
        height: 100
        anchors.left: parent.left
        anchors.topMargin: marginValue
        anchors.margins: marginValue


        Grid{
            id:inputGrid
            width:500
            height:80
            anchors.left: parent.left
            anchors.leftMargin: marginValue
            anchors.top: parent.top
            anchors.topMargin: marginValue
            rows:1
            columns:6
            spacing: 10

            Text {
                id: txtItetimes
                //anchors.left: parent.left
                text: qsTr("Max iteration\n"+"times:")

            }

            TextField{
                id:maxIteInputTxt
                width: 100
                height: 25
                placeholderText: "1000"
                selectByMouse: true
                 onEditingFinished:{
                     ////Todo
                   }////onEditingFinished Finish

            }

            Text {
                id: txtAccuracy
                //anchors.left: parent.left
                text: qsTr("Accuracy:")
            }

            TextField{
                id:inputAccuracy
                width: 100
                height: 25
                //anchors.right:  maxIteInputTxt.right
                selectByMouse: true

                placeholderText: "0.001"
                 onEditingFinished:{
                     ////Todo
                   }////onEditingFinished Finish

            }

            Text {
                id: txtOptMethod
                //anchors.left: parent.left
                text: qsTr("Optimization Method:")

            }

            ComboBox {
                id:comboBox_optMethod
                width: 200
                height: 25
                model: [ "Local gradient-based", "Derivative-free algorithm" ]
            }
        }


    }


    Component {
        id: variableName
        ////Input variable name, lower bound, upper bound...
        Row{
            id: rowInputs
            ////TextField for the variable name start.
            TextField {
                id:textFieldVariable
                width: 50
                height: 25
                //placeholderText: "Name"
                selectByMouse: true
                onEditingFinished:{
                //set the text of the textField to the ListElement's property.
                name = textFieldVariable.getText(0,20);
                //The following is an example of getting a certain ListElement by ID (3 in this example)
                //nameText.text = theModel_variableName.get(3).name
           }////onEditingFinished Finish

        }////TextField for the variable name end.

            ////TextField for the lower bound.
            TextField {
                id:textFieldLowerBound
                width: 80
                height: 25
               // placeholderText: "Lower bound"
                selectByMouse: true
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
                //placeholderText: "Upper bound"
                selectByMouse: true
                onEditingFinished:{

                   ////Add.
                    upperBound = textFieldUpperBound.getText(0,20)

                }////onEditingFinished Finish

        }////TextField for the upper bound Finish


            ////TextField for the Gradient
            TextField {
                id:textFieldGradient
                width: 80
                height: 25
               // placeholderText: "Gradient"
                selectByMouse: true

                onEditingFinished:{
                   ////Add.

                    JSFunc.gradInPutSetting();
                   // theModel_variableName.remove(index);
                    if(comboBox_optMethod.currentIndex==1)
                    {

                        textFieldGradient.clear();
                        placeholderText= "Gradient"
                        textFieldGradient.readOnly =true;
                        //textFieldGradient.color = "black";

                    }
                    else
                    {
                        Gradient = textFieldGradient.getText(0,20)
                        textFieldGradient.readOnly =false;

                    }

                    }

                } ///TextField for the Gradient Finish


            ////TextField for the InitialValue.
            TextField {
                id:textFieldInitialValue
                width: 80
                height: 25
                //placeholderText: "Initial Value"
                selectByMouse: true
                onEditingFinished:{

                   ////Add.
                    initialValue = textFieldInitialValue.getText(0,20)

                }////onEditingFinished Finish

        }////TextField for the InitialValue Finish


            Rectangle{
                width: 80
                height: 25

                    Text {
                        anchors.centerIn: parent

                        font.pixelSize: 10

                        text: solution
                    }

            }





//            ////TextField for the Solution.
//            TextField {
//                id:textFieldSolution
//                width: 80
//                height: 25
//                placeholderText: "Solution"
//                readOnly:true
//                selectByMouse: true
//                onEditingFinished:{

//                   ////Add.
//                    ////Us role "solution"

//                }////onEditingFinished Finish

//        }////TextField for the upper solution Finish


     }////Component end



    }////Component Finish


//    Component{
//        id:component_optimizedVarVal_id

//        Rectangle {
//            width: 50
//            height: 25
//            //anchors.centerIn: resultHead.Center
//            //anchors.right: recVarOptVal.right
//            //anchors.rightMargin: marginValue

//            color: ListView.isCurrentItem?"#157efb":"#53d769"
//            border.color: Qt.lighter(color, 1.1)

//            Text {
//                anchors.centerIn: parent

//                font.pixelSize: 10

//                text: "error"
//            }
//        }
//    }

    ////Warning dialog
    MessageDialog {
            id: messageDialog
            title: "May I have your attention please"
            text: "It's so cool that you are using Qt Quick."
            onAccepted: {
                console.log("And of course you could only agree.")
                Qt.quit()
            }
            Component.onCompleted: visible = false
        }

}
