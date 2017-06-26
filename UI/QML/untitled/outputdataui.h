#ifndef OUTPUTDATAUI_H
#define OUTPUTDATAUI_H
#include<QVector>
#include<QString>

class OutputDataUI
{
public:
    OutputDataUI();
    ~OutputDataUI();

    QVector<QString> getOptimizedVariableValue() const;
    void setOptimizedVariableValue(const QVector<QString> &value);

    QString getMinObjValue() const;
    void setMinObjValue(const QString &value);

private:
    ////the value of the variables after optimization
    QVector<QString> optimizedVariableValue;

    ////The minimum object value
    QString minObjValue;
};

#endif // OUTPUTDATAUI_H
