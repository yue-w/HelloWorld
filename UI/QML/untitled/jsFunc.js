



function qmlDataToCpp(){

    ////Set variable name to C++
    for(var j = 0; j< theModel_variableName.count; j++){

      testCallCpp.pushName(theModel_variableName.get(j).name);

    }

    ////Set lower bound to C++
    for(var i = 0; i< theModel_variableName.count; i++){

       testCallCpp.pushLowerBnd(theModel_variableName.get(i).lowerBound);
    }



   //testCallCpp.setLowerBnd(lowerBnds);
   //testCallCpp.test(theModel_variableName.get(1).name);//


    objResultTxt.text= "Minimium object value: " + testCallCpp.getObjOptedValue();

    for(var i = 0; i< theModel_variableName.count; i++){
//            var c = theModel_variableName.count;
//             theModel_variableName.get(i);
//             nameText2.text +=theModel_variableName.get(i).lowerBound;
        var tem = theModel_variableName.get(i).solution;




    }

}

