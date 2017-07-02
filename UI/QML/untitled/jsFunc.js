//function test(cpp,theModel_variableName)
//{
//    ////Set variable name to C++
//    for(var j = 0; j< theModel_variableName.count; j++){

//      testCallCpp.pushName(theModel_variableName.get(j).name);

//    }
//}

function qmlDataToCpp(){

    //name:""; lowerBound:""; upperBound:"";initialValue:"";Gradient:""; solution:""

    ////Set variable name to C++
    for(var j = 0; j< theModel_variableName.count; j++){

      testCallCpp.pushName(theModel_variableName.get(j).name);

    }

    ////Set upper bound to C++
    for(var k = 0; k< theModel_variableName.count; k++){


        var a = theModel_variableName.get(k).upperBound;
       testCallCpp.pushUpperBnd(theModel_variableName.get(k).upperBound);
    }

    ////Set lower bound to C++
    for(var i = 0; i< theModel_variableName.count; i++){

       testCallCpp.pushLowerBnd(theModel_variableName.get(i).lowerBound);
    }

    ////Set Gradient value to C++
    for(var i = 0; i< theModel_variableName.count; i++){

       testCallCpp.pushGradient(theModel_variableName.get(i).Gradient);
    }

    ////Set initial value to C++
    for(var i = 0; i< theModel_variableName.count; i++){

       testCallCpp.pushInitialValue(theModel_variableName.get(i).initialValue);
    }

    ////Set object function
    testCallCpp.setObjectFunction(objectFunction.text);

    ////Set optimization method
    var optMethod = comboBox_optMethod.currentIndex;
    testCallCpp.setOptMethod(optMethod);

}

function letsGo()
{
    uiLogicalCheck();

}

function excute()
{


    ////Transfer UI Data to Cpp;
    qmlDataToCpp();

    ////Excute Optimization
    testCallCpp.doOptimize();

    ////Show the optimization result to UI
    minTxtField.text = testCallCpp.getOptimizedObjValue();
}

function uiLogicalCheck()
{

////Some logic here
    if(gradientCheck())
    {
       //messageDialog.visible = true;
    }
    else
    {
       excute();
    }




}

function gradientCheck()
{



    return true;
}

function gradInPutSetting()
{


    if(comboBox_optMethod.currentIndex == 1)
    {


        //textFieldGradient.clear();
        //theModel_variableName.setProperty(0,"name"," ");
        //theModel_variableName.remove(0);
    }


}
