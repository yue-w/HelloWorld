#ifndef CALLCPPFROMQML_H
#define CALLCPPFROMQML_H

#include <QObject>
//#include "uidata.h"
#include <QVector>
#include <QString>
#include <string>
#include <unordered_map>


class UIData;
class OutputDataUI;
class OutputUI;
enum optMethod;

namespace Core {

class AlgorithmInteractive;

}

class CallCppFromQml : public QObject
{
    Q_OBJECT
private:
    UIData* _uiData;

    ////Output data to UI. Optimized from C++
    OutputDataUI* _outputDataUI;

    OutputUI* _outputUI;

    //std::unordered_map<std::string, optMethod> _undMapOptMethod;

public:
    explicit CallCppFromQml(QObject *parent = 0);

    Q_INVOKABLE QString test(int a);
    Q_INVOKABLE void pushLowerBnd(QString oneLowerBnd);
    Q_INVOKABLE void pushUpperBnd(QString oneUpperBnd);
    Q_INVOKABLE void pushInitialValue(QString oneinitialValue);
    Q_INVOKABLE void pushName(QString oneName);
    Q_INVOKABLE void setObjectFunction(QString value);
    Q_INVOKABLE void setOptMethod(int value);
    Q_INVOKABLE void pushGradient(QString oneGradient);
    Q_INVOKABLE bool doOptimize();
    Q_INVOKABLE void pushInequalFunc(QString oneInequalFunc);
    Q_INVOKABLE void pushGradient_InequalFunc(QString oneInequalFunc /*, int numOfInequalFunc, int index*/);

    UIData *uiData() const;
    void setUiData(UIData *uiData);

    OutputDataUI *outputDataUI() const;
    void setOutputDataUI(OutputDataUI *outputDataUI);

    Q_INVOKABLE QString getOptimizedObjValue();

    Q_INVOKABLE QVector<QString> getOptimizedVarValue();

    Q_INVOKABLE QString getOneVarValue( int index);
    Q_INVOKABLE QString getTest(int index);


private:
    Q_INVOKABLE void TransferDataToCpp(Core::AlgorithmInteractive* interative, const UIData* _uiData);
    Q_INVOKABLE void TransferDataToCppExcute(Core::AlgorithmInteractive* interative, QString key,QVector<QString> vecValue);

    ////TransferDataToCppExcute_Grid is used to deal with grid (matrix) form, such as gradient.
    Q_INVOKABLE void TransferDataToCppExcute_Grid(int column,Core::AlgorithmInteractive* interative, QString key,QVector<QString> vecValue);

    Q_INVOKABLE void addNameKey(std::string aNameKey);


    Q_INVOKABLE void parseOptimizedVariableValue(/*const OutputDataUI * optResutl*/const std::unordered_map<std::string, std::string>* val);


signals:

public slots:
};

#endif // CALLCPPFROMQML_H
