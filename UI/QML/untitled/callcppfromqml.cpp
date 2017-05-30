#include "callcppfromqml.h"
#include <QDebug>
#include "uidata.h"
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

CallCppFromQml::CallCppFromQml(QObject *parent) : QObject(parent),_uiData(new UIData)
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

void CallCppFromQml::setObjectFunction(QString value)
{
    _uiData->setObjectFunction(value);

}

bool CallCppFromQml::doOptimize()
{
//    Core::AlgorithmInteractive interative;
//    interative.AddParam("x1key", "x1");
//    interative.AddParam("x2key", "x2");

//    ////map that contains the object function
//    interative.AddParam("objFunc", "x1*x1+x2*x2");

//    if (interative.Execute("Optimization"))
//    {
//        unordered_map<string, string> outData = interative.GetOutput();
//        string modifiedObj = outData.at("modi");
//        int c= 0;

//    }



    Core::AlgorithmInteractive* interative = new Core::AlgorithmInteractive ;
    TransferDataToCpp(interative,uiData());


        if (interative->Execute("Optimization"))
        {
            unordered_map<string, string> outData = interative->GetOutput();
            string modifiedObj = outData.at("modi");
            int c= 0;

        }

    ////Modify the return value.
    return true;
}

void CallCppFromQml::TransferDataToCpp(Core::AlgorithmInteractive *interative, const UIData *_uiData)
{
//    ////Transfer variable name
//    for(int i =0; i< _uiData->vecVariableName().size(); i++)
//    {
//        QString str;
//        str.setNum(i+1);
//        QString key = "varName"+str;
//        TransferDataToCppExcute(interative, key ,_uiData->vecVariableName()[i]);
//    }

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

    //Transfer initial value
    keyValue = "initVal";
    TransferDataToCppExcute(interative,keyValue, _uiData->vecInitialValue() );

    //Transfer object function
    QString objStr = _uiData->objectFunction();
    interative->AddParam("objFunc", objStr.toStdString());

    //transfer the vector that contains all the keys of the name
    interative->setVarNameKey(_uiData->vecNameKeys().toStdVector());

    int c = 0;
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


