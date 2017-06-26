#include "outputdataui.h"



OutputDataUI::OutputDataUI()
{

}

OutputDataUI::~OutputDataUI()
{

}

QVector<QString> OutputDataUI::getOptimizedVariableValue() const
{
    return optimizedVariableValue;
}

void OutputDataUI::setOptimizedVariableValue(const QVector<QString> &value)
{
    optimizedVariableValue = value;
}

QString OutputDataUI::getMinObjValue() const
{
    return minObjValue;
}

void OutputDataUI::setMinObjValue(const QString &value)
{
    minObjValue = value;
}
