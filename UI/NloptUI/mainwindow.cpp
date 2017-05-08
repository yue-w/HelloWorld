#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    lineEdit = new QLineEdit("Hello World", this);
    lineEdit->show();
}
