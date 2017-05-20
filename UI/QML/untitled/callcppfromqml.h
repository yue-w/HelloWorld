#ifndef CALLCPPFROMQML_H
#define CALLCPPFROMQML_H

#include <QObject>

class CallCppFromQml : public QObject
{
    Q_OBJECT
public:
    explicit CallCppFromQml(QObject *parent = 0);

signals:

public slots:
};

#endif // CALLCPPFROMQML_H