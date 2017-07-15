#ifndef UIDATA_H
#define UIDATA_H
#include<QVector>
#include<QString>
//#include <unordered_map>
//#include<string>


//enum optMethod{

//    LD_MMA=25,
//    LN_COBYLA=26
//};


class UIData
{
private:

    QVector<QString> _vecVariableName;
    QVector<QString> _vecLowerBnd;
    QVector<QString> _vecUpperBnd;
    QVector<QString> _vecinitialValue;
    QVector<QString> _vecGradient;
    QVector<QString> _vecGradient_InequalFunc;
    QVector<QString> _vecInequalFunc;
    QString _objectFunction;
    QVector<std::string> _vecNameKeys;
    QString _optMethod;

   // std::unordered_map<std::string, optMethod> _undMapOptMethod;

public:
    UIData();
    ~UIData();

    QVector<QString> vecLowerBnd() const;
    void pushLowerBnd(const QString value);


    QVector<QString> vecVariableName() const;
    void pushvariableName(const QString value);

    QVector<QString> vecUpperBnd() const;
    void pushUpperBnd(const QString value);

    QVector<QString> vecGradient() const;
    void pushGradient(const QString value);

    QVector<QString> vecInitialValue() const;
    void pushInitialValue(const QString value);



    QString objectFunction() const;
    void setObjectFunction(const QString &objectFunction);

    QVector<std::string> vecNameKeys() const;
    void pushNameKey(const std::string aKey);

    QString getoptMethod() const;
    void setOptMethod(const QString &optMethod);


    QVector<QString> getVecInequalFunc() const;
    void pushInequalFunc(const QString value);

    void pushGradofInequalFunc(const QString value);
    QVector<QString> getGradofInequalFunc() const;

};

#endif // UIDATA_H
