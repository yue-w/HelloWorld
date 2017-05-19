#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <string.h>


#include "../../../Core/AlgorithmInteractive.h"

#pragma comment(lib,"../../Core/x64/Debug/Core.lib")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_optimize, SIGNAL(clicked()), this, SLOT(on_pushButton_optimize_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_optimize_clicked()
{
    ////Test
    /// Add widget dynamically
    //lineEdit = new QLineEdit("Hello World", this);
    //lineEdit->show();

    auto lb1=ui->lineEdit_lowerbound1->text().toStdString();
    auto func=ui->lineEdit_objectFunction->text().toStdString();

    Core::AlgorithmInteractive interactive_test;
    interactive_test.AddParam("lb0",lb1);
    interactive_test.AddParam("objFunc",func);
    if(interactive_test.Execute("Optimization"))
    {
        auto outData_test=interactive_test.GetOutput();
        auto res=outData_test["objVal"];
        qDebug("res: %s",res.c_str());
    }
    else
    {
        auto outData_test=interactive_test.GetOutput();
        auto res=outData_test["error"];
        qDebug("error: %s",res.c_str());
    }

    //Get lowerbounds of Two variables and then input them into TestOptimize.
    //After optimization, get two optimized variables finally.
//    auto lb1=ui->lineEdit_lowerbound1->text().toStdString();
//    auto lb2=ui->lineEdit_lowerbound2->text().toStdString();

//    Core::AlgorithmInteractive interactive;
//    interactive.AddParam("lb0",lb1);
//    interactive.AddParam("lb1",lb2);

//    interactive.Execute("Optimization");
//    auto outData=interactive.GetOutput();
//    auto var0=outData["var0"];
//    auto var1=outData["var1"];

//    qDebug("var1: %s",var0.c_str());
//    qDebug("var2: %s",var1.c_str());

//    ui->lineEdit_variable1_output->setText(QString::fromStdString(var0));
//    ui->lineEdit_variable2_output->setText(QString::fromStdString(var1));
}


