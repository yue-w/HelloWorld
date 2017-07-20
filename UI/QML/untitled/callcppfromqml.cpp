#include "callcppfromqml.h"
#include <QDebug>
#include "uidata.h"
#include "outputdataui.h"
#include "outputui.h"
#include <string>
#include "../../../Core/AlgorithmInteractive.h"

using namespace Core;
UIData *CallCppFromQml::uiData() const
{
    return _uiData;
}

void CallCppFromQml::setUiData(UIData *uiData)
{
    _uiData = uiData;
}





OutputDataUI *CallCppFromQml::outputDataUI() const
{
    return _outputDataUI;
}

void CallCppFromQml::setOutputDataUI(OutputDataUI *outputDataUI)
{
    _outputDataUI = outputDataUI;
}

QString CallCppFromQml::getOptimizedObjValue()
{
      return _outputDataUI->getMinObjValue();
}

QVector<QString> CallCppFromQml::getOptimizedVarValue()
{
    return _outputDataUI->getOptimizedVariableValue();
}



CallCppFromQml::CallCppFromQml(QObject *parent) : QObject(parent),_uiData(new UIData),_outputDataUI(new OutputDataUI)
{

    //_uiData = new UIData();
}



QString CallCppFromQml::test(int a)
{


    //int c = a ;

    return "QString::from";

}

void CallCppFromQml::pushLowerBnd(QString oneLowerBnd)
{

    _uiData->pushLowerBnd(oneLowerBnd);
}

void CallCppFromQml::pushUpperBnd(QString oneUpperBnd)
{
    _uiData->pushUpperBnd(oneUpperBnd);
}

void CallCppFromQml::pushInitialValue(QString oneinitialValue)
{
    _uiData->pushInitialValue(oneinitialValue);
}

void CallCppFromQml::pushName(QString oneName)
{
    _uiData->pushvariableName(oneName);
}


void CallCppFromQml::pushGradient(QString oneGradient)
{
     _uiData->pushGradient(oneGradient);
}

void CallCppFromQml::setObjectFunction(QString value)
{
    _uiData->setObjectFunction(value);

}

void CallCppFromQml::pushInequalFunc(QString oneInequalFunc)
{
    _uiData->pushInequalFunc(oneInequalFunc);
}

void CallCppFromQml::pushGradient_InequalFunc(QString oneInequalFunc /*,int numOfInequalFunc, int index*/)
{
//    int jthVar = index / numOfInequalFunc +1;
//    int ithGrad = index % numOfInequalFunc +1;
//    if(0==ithGrad)
//    {
//        ithGrad = numOfInequalFunc;
//    }


//    QString ithGradS = QString::number(ithGrad);
//    QString jthvarS = QString::number(jthVar);
//    QString test = oneInequalFunc+ithGradS+jthvarS;
    _uiData->pushGradofInequalFunc(oneInequalFunc);


}

void CallCppFromQml::setOptMethod(int value)
{

    _uiData->setOptMethod(QString::number(value));

}



bool CallCppFromQml::doOptimize()
{

    Core::AlgorithmInteractive* interative = new Core::AlgorithmInteractive ;
    TransferDataToCpp(interative,uiData());


    if (interative->Execute("Optimization"))
    {
        unordered_map<string, string> outData = interative->GetOutput();
        string minObjValStr = outData["minObjVal"];


        QString minObjValStrQstr = QString::fromStdString(minObjValStr);
        _outputDataUI->setMinObjValue(minObjValStrQstr);


       // vector<std::string> varOptValue = outData;
        //std::unordered_map<std::string, std::string>
        parseOptimizedVariableValue(&outData);
        //double minObjVal = std::stod(minObjValStr);

    }

    ////Modify the return value.
    return true;
}



void CallCppFromQml::TransferDataToCpp(Core::AlgorithmInteractive *interative, const UIData *_uiData)
{
    QString keyValue = "";

    //Transfer variable name
    keyValue = "varName";
    TransferDataToCppExcute(interative,keyValue, _uiData->vecVariableName() );


    //Transfer lower bound
    keyValue = "lowBnd";
    TransferDataToCppExcute(interative,keyValue, _uiData->vecLowerBnd() );

    //Transfer higher bound
    keyValue = "upBnd";
    TransferDataToCppExcute(interative,keyValue, _uiData->vecUpperBnd() );

    //Transfer gradient
    keyValue ="grad";
    TransferDataToCppExcute(interative,keyValue, _uiData->vecGradient() );

    //Transfer initial value
    keyValue = "initVal";
    TransferDataToCppExcute(interative,keyValue, _uiData->vecInitialValue() );

    //Transfer object function
    QString objStr = _uiData->objectFunction();
    interative->AddParam("objFunc", objStr.toStdString());

    //Transfer optimization method
    QString optMthod = _uiData->getoptMethod();
    interative->AddParam("optMethod" ,optMthod.toStdString());

    //transfer the vector that contains all the keys of the name
    interative->setVarNameKey(_uiData->vecNameKeys().toStdVector());

    //transfer the inequality function
    keyValue = "inequalCnst";
    TransferDataToCppExcute(interative,keyValue, _uiData->getVecInequalFunc() );

    //Transfer the gradient for inequality function
    keyValue = "inequalGrad";
    int numOfInequalFunc = _uiData->getVecInequalFunc().size();
    TransferDataToCppExcute_Grid(numOfInequalFunc,interative,keyValue, _uiData->getGradofInequalFunc() );



}

void CallCppFromQml::TransferDataToCppExcute(Core::AlgorithmInteractive* interative, QString key,QVector<QString> vecValue)
{

    for(int i =0; i< vecValue.size(); i++)
    {
        QString str;
        str.setNum(i+1);
        QString temStr= key +str;
        //add a key and value
        interative->AddParam(temStr.toStdString(),  vecValue[i].toStdString());

        //if the key is varName, store it
        if(key=="varName")
        {
           addNameKey(temStr.toStdString());
        }
    }

}

void CallCppFromQml::TransferDataToCppExcute_Grid(int column, AlgorithmInteractive *interative, QString key, QVector<QString> vecValue)
{
    for(int i =0; i< vecValue.size(); i++)
    {
        int jthVar = i / column +1;
        int ithInequal = i % column +1;
        QString jthVarS;
        jthVarS.setNum(jthVar);
        QString ithInequalS;
        ithInequalS.setNum(ithInequal);
        QString temStr= key +ithInequalS+jthVarS;
        interative->AddParam(temStr.toStdString(),  vecValue[i].toStdString());
    }

}

void CallCppFromQml::addNameKey(std::string aNameKey)
{
    _uiData->pushNameKey(aNameKey);

}

void CallCppFromQml::parseOptimizedVariableValue(const std::unordered_map<std::string, std::string>* val )
{

    //std::unordered_map<std::string, std::string> val = optResutl->getOptimizedVariableValue();
    //Number of variables
    int numOfVar = _uiData->vecNameKeys().size();
    QVector<QString> results(numOfVar);
    for(int i = 1; i<numOfVar+1; i++)
    {
        std::string key = "optVal";
        QString ith;
        ith.setNum(i);
        std::string ithStd = ith.toStdString();
        key += ithStd;
        if(val->find(key)!= val->end())
        {
            results[i-1]= QString::fromStdString(val->at(key)) ;
        }
        else {
           // throw Error;
        }

    }
    _outputDataUI->setOptimizedVariableValue(results);
}

QString CallCppFromQml::getOneVarValue(int index)
{
    return _outputDataUI->getOneVarValue(index);
}

QString CallCppFromQml::getTest(int index)
{
    int c = index;
    QString test = "";
    return test;
}


