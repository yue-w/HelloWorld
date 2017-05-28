#include "callcppfromqml.h"
#include <QDebug>
#include "uidata.h"
#include <string>
CallCppFromQml::CallCppFromQml(QObject *parent) : QObject(parent),_uiData(new UIData)
{

    //_uiData = new UIData();
}



void CallCppFromQml::test(QString name)
{


    qDebug()<<"Hello From Cpp";
    QString a = name;


}

void CallCppFromQml::pushLowerBnd(double oneLowerBnd)
{

    _uiData->pushLowerBnd(oneLowerBnd);
}

void CallCppFromQml::pushUpperBnd(double oneUpperBnd)
{
    _uiData->pushUpperBnd(oneUpperBnd);
}

void CallCppFromQml::pushInitialValue(double oneinitialValue)
{
    _uiData->pushInitialValue(oneinitialValue);
}

void CallCppFromQml::pushName(QString oneName)
{
    _uiData->pushvariableName(oneName);
}


