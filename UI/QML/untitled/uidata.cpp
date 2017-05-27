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



void UIData::addLowerBnd(const double variable)
{
    _vecLowerBnd.push_back(variable);
}

void UIData::addvariableName(const QString variable)
{
    _vecVariableName.push_back(variable);
}

QVector<QString> UIData::vecVariableName() const
{
    return _vecVariableName;
}

