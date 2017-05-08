#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <string.h>

#include "../../../Core/Command.h"

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
    std::vector<std::string> lowerbound;
    lowerbound.push_back(lb1);
    lowerbound.push_back(lb2);

    std::vector<double> vars;
    Core::TestOptimize(lowerbound,vars);

    qDebug("var1: %lf",vars[0]);
    qDebug("var2: %lf",vars[1]);

    ui->lineEdit_variable1_output->setText(QString::number(vars[0]));
    ui->lineEdit_variable2_output->setText(QString::number(vars[1]));
}
