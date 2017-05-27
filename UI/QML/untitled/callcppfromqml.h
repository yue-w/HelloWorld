#ifndef CALLCPPFROMQML_H
#define CALLCPPFROMQML_H

#include <QObject>
#include "uidata.h"
#include <QVector>
#include <QString>
#include <string>
class UIData;

class CallCppFromQml : public QObject
{
    Q_OBJECT
private:
    UIData* _uiData;
public:
    explicit CallCppFromQml(QObject *parent = 0);

    Q_INVOKABLE void test(QString name);
    Q_INVOKABLE void pushLowerBnd(double oneLowerBnd);
    Q_INVOKABLE void pushName(QString oneName);



signals:

public slots:
};

#endif // CALLCPPFROMQML_H
