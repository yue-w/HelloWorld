#ifndef UIDATA_H
#define UIDATA_H
#include<QVector>
#include<QString>

class UIData
{
public:
    UIData();
    ~UIData();

    QVector<QString> vecLowerBnd() const;
    void pushLowerBnd(const QString value);


    QVector<QString> vecVariableName() const;
    void pushvariableName(const QString value);

    QVector<QString> vecUpperBnd() const;
    void pushUpperBnd(const QString value);

    QVector<QString> vecInitialValue() const;
    void pushInitialValue(const QString value);

    QString objectFunction() const;
    void setObjectFunction(const QString &objectFunction);

private:
    QVector<QString> _vecVariableName;
    QVector<QString> _vecLowerBnd;
    QVector<QString> _vecUpperBnd;
    QVector<QString> _vecinitialValue;
    QString _objectFunction;
};

#endif // UIDATA_H
