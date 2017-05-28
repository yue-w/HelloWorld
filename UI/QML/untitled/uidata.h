#ifndef UIDATA_H
#define UIDATA_H
#include<QVector>
#include<QString>

class UIData
{
public:
    UIData();
    ~UIData();

    QVector<double> vecLowerBnd() const;
    void pushLowerBnd(const double value);


    QVector<QString> vecVariableName() const;
    void pushvariableName(const QString value);

    QVector<double> vecUpperBnd() const;
    void pushUpperBnd(const double value);

    QVector<double> vecInitialValue() const;
    void pushInitialValue(const double value);

private:
    QVector<QString> _vecVariableName;
    QVector<double> _vecLowerBnd;
    QVector<double> _vecUpperBnd;
     QVector<double> _vecinitialValue;
};

#endif // UIDATA_H
