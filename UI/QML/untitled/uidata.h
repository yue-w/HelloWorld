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
    void addLowerBnd(const double variable);


    QVector<QString> vecVariableName() const;
    void addvariableName(const QString variable);

private:
    QVector<QString> _vecVariableName;
    QVector<double> _vecLowerBnd;
};

#endif // UIDATA_H
