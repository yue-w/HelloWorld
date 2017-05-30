#include "uidata.h"

UIData::UIData()
{

}

UIData::~UIData()
{

}

QVector<QString> UIData::vecLowerBnd() const
{
    return _vecLowerBnd;
}



void UIData::pushLowerBnd(const QString value)
{
    _vecLowerBnd.push_back(value);
}

void UIData::pushvariableName(const QString value)
{
    _vecVariableName.push_back(value);
}

QVector<QString> UIData::vecUpperBnd() const
{
    return _vecUpperBnd;
}

void UIData::pushUpperBnd(const QString value)
{
    _vecUpperBnd.push_back(value);
}

QVector<QString> UIData::vecInitialValue() const
{
    return _vecinitialValue;
}

void UIData::pushInitialValue(const QString value)
{
    _vecinitialValue.push_back(value);
}

QString UIData::objectFunction() const
{
    return _objectFunction;
}

void UIData::setObjectFunction(const QString &objectFunction)
{
    _objectFunction = objectFunction;
}

QVector<std::string> UIData::vecNameKeys() const
{
    return _vecNameKeys;
}

void UIData::pushNameKey(const std::string aKey)
{

    _vecNameKeys.push_back(aKey);
}


QVector<QString> UIData::vecVariableName() const
{
    return _vecVariableName;
}

