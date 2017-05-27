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

    _uiData->addLowerBnd(oneLowerBnd);
}

void CallCppFromQml::pushName(QString oneName)
{
    _uiData->addvariableName(oneName);
}


