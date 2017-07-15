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
    var debug = theModel_variableName.count;
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

//    ////Set inequality constraint function and correspond gradient
//    for(var i = 0; i< restRepeater.count; i++){

//        var a = restRepeater.itemAt(i).text
//        var cc =0;
//    }


    var numOfInequal = grid_ineqFun_grad.columns;
    for(var i = 0; i< repeaterInequalityFunAndGrad.count; i++){

       //Set inequality function

        if(i<numOfInequal){
            //var debug = repeaterInequalityFunAndGrad.itemAt(i).text;
            testCallCpp.pushInequalFunc(repeaterInequalityFunAndGrad.itemAt(i).text);
            continue;
        }

       //the index for the current gradient. Start from 0
        var index = i - grid_ineqFun_grad.columns;
        //Set gradient for inequality function
        testCallCpp.pushGradient_InequalFunc(repeaterInequalityFunAndGrad.itemAt(i).text,grid_ineqFun_grad.columns,index );


    }




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

    ////Show the variable value after optimization
    //var num = testCallCpp.getOptimizedVariableValue.size();
    showOptimizedValue(/*num*/);
}

function uiLogicalCheck()
{

////Some logic here
    if(gradientCheck())
    {
       //messageDialog.visible = true;
       excute();
    }
    else
    {
       excute();
    }


//    for(var cc = 0; cc<theModel_variableName.count; cc++)
//    {

//        theModel_variableName.get(cc).solution = "Hello";

//        var tt = theModel_variableName.get(cc).solution;

//        var ddd = 0;
//    }




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

function addInequalityFuncAndGrad(){

    var colums = grid_ineqFun_grad.columns;
    var total = repeaterInequalityFunAndGrad.model;
    var rows = total/colums;
    var newColums=colums +1;
    var newTotal = newColums*rows;
    repeaterInequalityFunAndGrad.model = newTotal;
    grid_ineqFun_grad.columns = newColums;
}

function showOptimizedValue(/*numOfVar*/){

    for(var i = 0; i<theModel_variableName.count; i++)
    {

        var value = testCallCpp.getOneVarValue(i);
         theModel_variableName.get(cc).solution =value;

    }
}
