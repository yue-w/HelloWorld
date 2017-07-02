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

CallCppFromQml::CallCppFromQml(QObject *parent) : QObject(parent),_uiData(new UIData),_outputDataUI(new OutputDataUI)
{

    //_uiData = new UIData();
}



void CallCppFromQml::test(QString name)
{


    qDebug()<<"Hello From Cpp";
    QString a = name;


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

void CallCppFromQml::setOptMethod(int value)
{

//    switch (value) {
//    case 0:
//        _uiData->setOptMethod(LD_MMA);
//        break;
//    case 1:
//         _uiData->setOptMethod(LN_COBYLA);
//        break;
//    default:
//        _uiData->setOptMethod(LD_MMA);
//        break;
//    }

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

void CallCppFromQml::addNameKey(std::string aNameKey)
{
    _uiData->pushNameKey(aNameKey);

}


