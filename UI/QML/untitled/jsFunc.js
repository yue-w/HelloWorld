


////The number of input for each variable, which include variable name,
////lower bound, upper bound, gradient, and initial value.
var numOfInputEachVariable = 5;


function qmlDataToCpp(){



/*
    ////Set variable name to C++
    //var debug = theModel_variableName.count;
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

*/

    var indexInput = 0;
    var total = userInputRepeater_id.model
    var numOfVariable = total/numOfInputEachVariable;
    for(var i = 0; i<numOfVariable; i++){

        ////Set variable name
        testCallCpp.pushName(  userInputRepeater_id.itemAt(indexInput).text  );

        ////Set lower bound to C++
         testCallCpp.pushLowerBnd(userInputRepeater_id.itemAt(indexInput+1).text );

        ////Set upper bound to C++
        testCallCpp.pushUpperBnd(userInputRepeater_id.itemAt(indexInput+2).text);

        ////Set Gradient value to C++
        testCallCpp.pushGradient(userInputRepeater_id.itemAt(indexInput+3).text);


        ////Set initial value to C++
        testCallCpp.pushInitialValue(userInputRepeater_id.itemAt(indexInput+4).text);

        indexInput +=5;

    }

    ////Set object function
    testCallCpp.setObjectFunction(objectFunction.text);

    ////Set optimization method
    var optMethod = comboBox_optMethod.currentIndex;
    testCallCpp.setOptMethod(optMethod);

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

//        var a = "1";
//        theModel_variableName.get(cc).solution = "a";

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

    var numOfVar = userInputRepeater_id.model/numOfInputEachVariable;
    var test = optimizedVarVal_id.model;
    optimizedVarVal_id.model = numOfVar;
    for(var i = 0; i<numOfVar; i++)
    {

        optimizedVarVal_id.itemAt(i).optRest = testCallCpp.getOneVarValue(i);

    }

}

function setInequalityGrad(){


    var numOfVar = userInputRepeater_id.model/numOfInputEachVariable;

    var colums = grid_ineqFun_grad.columns;
    var total = repeaterInequalityFunAndGrad.model;

    var newTotal = (numOfVar+1)*colums;

    repeaterInequalityFunAndGrad.model = newTotal;

}

function addAVariable(){

   var oldModel = userInputRepeater_id.model;
    userInputRepeater_id.model = oldModel +numOfInputEachVariable ;
    //userinput_id.columns = 5;
   // var total = userInputRepeater_id.model;
   // userInputRepeater_id.model = total+5;

}

