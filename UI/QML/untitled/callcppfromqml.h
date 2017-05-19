#ifndef CALLCPPFROMQML_H
#define CALLCPPFROMQML_H
#include <vector>

#include <QObject>
#include <QVector>
//#include "../../../Core/DebugCppAndQml.h"
#include "../../../Core/AlgorithmInteractive.h"
class CallCppFromQml : public QObject
{
    Q_OBJECT
public:
    explicit CallCppFromQml(QObject *parent = 0);
    Q_INVOKABLE QVector<double> test();
    Q_INVOKABLE void setLowerBound(QVector<double> dataFromQml);
    Q_INVOKABLE double getObjOptedValue() { return m_objFunValue;}

signals:

public slots:

private:
    double m_objFunValue;
    std::vector<double> m_lowerBound;
};

#endif // CALLCPPFROMQML_H
