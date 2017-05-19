#include "callcppfromqml.h"
#include <QDebug>
using namespace Core;



CallCppFromQml::CallCppFromQml(QObject *parent) : QObject(parent)
{

}

QVector<double> CallCppFromQml::test( )
{
//    qDebug()<<"Hello!";

//        std::vector<std::string> lowerbound;
//        lowerbound.push_back("0");
//        lowerbound.push_back("0");

//        //std::vector<double> vars;
        std::vector<double> variable;


//        OptimizationCommand command;
//        m_objFunValue =command.TestOptimize(lowerbound,variable);
//       // m_objFunValue = testCPPQml::TestOptimize(m_lowerBound,variable);

//       // m_objFunValue = Core::TestOptimize(m_lowerBound,variable);

        QVector<double> optedVec = QVector<double>::fromStdVector(variable);


        ////Add code to show the result from TestOptimize to UI
        return optedVec;




}

void CallCppFromQml::setLowerBound(QVector<double> dataFromQml)
{
    m_lowerBound = dataFromQml.toStdVector();

}
