////The number of input for each variable, which include variable name,
////lower bound, upper bound, gradient, and initial value.
var numOfInputEachVariable = 5;

function start() {


    //var testTxt = textPage1_id.text;
    startPage_id.hide();

    var component = Qt.createComponent("main.qml");
    var loadwin    = component.createObject(startPage_id);


    var numberOfVariable = numOfVar_input_id.text;
    var numberOfVariableInt = parseInt(numberOfVariable);
    loadwin.numOfVariable = numberOfVariableInt;
    //var test = numOfInputEachVariable* numberOfVariableInt;
    loadwin.inputMatrixTotal= numOfInputEachVariable* numberOfVariableInt;


    var numOfInequalFunc =  numOfInequalFunc_input_id.text;
     var  numOfInequalFuncInt = parseInt(numOfInequalFunc);
    loadwin.numOfInequalFunc =numOfInequalFuncInt;

    //var test2 = numOfInequalFuncInt * numberOfVariableInt + numOfInequalFuncInt;
    loadwin.numOfInequalFuncAndGradInput= numOfInequalFuncInt * numberOfVariableInt + numOfInequalFuncInt;


    loadwin.show();


}
