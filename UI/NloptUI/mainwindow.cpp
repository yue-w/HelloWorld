#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <string.h>

<<<<<<< HEAD
#include "../../../Core/Command.h"
#include <QDebug>
=======
#include "../../../Core/AlgorithmInteractive.h"
>>>>>>> 6642de20967f6defeb691c953c77675de27b5fd9

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

    //Get lowerbounds of Two variables and then input them into TestOptimize.
    //After optimization, get two optimized variables finally.
    auto lb1=ui->lineEdit_lowerbound1->text().toStdString();
    auto lb2=ui->lineEdit_lowerbound2->text().toStdString();

    Core::AlgorithmInteractive interactive;
    interactive.AddParam("lb0",lb1);
    interactive.AddParam("lb1",lb2);

    auto outData=interactive.Execute("Optimization");
    auto var0=outData["var0"];
    auto var1=outData["var1"];

    qDebug("var1: %s",var0.c_str());
    qDebug("var2: %s",var1.c_str());

    ui->lineEdit_variable1_output->setText(QString::fromStdString(var0));
    ui->lineEdit_variable2_output->setText(QString::fromStdString(var1));
}


