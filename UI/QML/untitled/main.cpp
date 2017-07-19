#include <QGuiApplication>
#include <QQmlApplicationEngine>
////YueWang
#include<QQmlEngine>
#include<QQmlContext>
#include "callcppfromqml.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ////wrape the pointer in th QScopedPointer, which is used to monitor the memory
    QScopedPointer<CallCppFromQml> testCallCpp (new CallCppFromQml);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/startPage.qml")));


    engine.rootContext()->setContextProperty("testCallCpp",testCallCpp.data());



    return app.exec();
}
