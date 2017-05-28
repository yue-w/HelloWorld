#include "uidata.h"

UIData::UIData()
{

}

UIData::~UIData()
{

}

QVector<double> UIData::vecLowerBnd() const
{
    return _vecLowerBnd;
}



void UIData::pushLowerBnd(const double value)
{
    _vecLowerBnd.push_back(value);
}

void UIData::pushvariableName(const QString value)
{
    _vecVariableName.push_back(value);
}

QVector<double> UIData::vecUpperBnd() const
{
    return _vecUpperBnd;
}

void UIData::pushUpperBnd(const double value)
{
    _vecUpperBnd.push_back(value);
}

QVector<double> UIData::vecInitialValue() const
{
    return _vecinitialValue;
}

void UIData::pushInitialValue(const double value)
{
    _vecinitialValue.push_back(value);
}

QVector<QString> UIData::vecVariableName() const
{
    return _vecVariableName;
}

