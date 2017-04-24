#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ////original value
    m_firstString = true;

    ////Signal and slot for the digit
    connect(ui->pushButton_0,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()), this, SLOT(digit_pressed()));


    ////Signal and slot for unary operation
    connect(ui->pushButton_plusMinus,SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    ////Signal and solt for %
    connect(ui->pushButton_percent,SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    ////Signal and solt for + _ * /
    connect(ui->pushButton_plus,SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_subtract,SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()), this, SLOT(binary_operation_pressed()));

    ////Signal and slot for =
    connect(ui->pushButton_equal,SIGNAL(released()), this, SLOT(on_pushButton_equal_released()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_subtract->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    // ui->pushButton_decimal->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    ////which button is clicked
    /// We know it will be a QPushbutton here, so cast the return value to QPushbutton
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    ////if operator is clicked, delete the label
    if( (ui->pushButton_multiply->isChecked() || ui->pushButton_divide->isChecked() ||
            ui->pushButton_plus->isChecked() || ui->pushButton_subtract->isChecked() )   &&
            (m_firstString == true))
    {
         labelNumber = button->text().toDouble();

         ////change the double to QString, the third parameter is the precision
         newLabel = QString::number(labelNumber,'g',15);

         m_firstString = false;

    }
    ////else, append the new digit to the old one
    else
    {

        ////ui->label->text() return the QString in the label
        /// button->text()     return the QString in the button that clicked
        /// combine the text in the label and the number of the clicked button
        /// Use toDouble method to change the QString to Double.


        if(ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel =ui->label->text() +button->text();

        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            ////change the double to QString, the third parameter is the precision
            newLabel = QString::number(labelNumber,'g',15);
        }

    }


    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();

    double labelNumber;
    QString newLabel;

    if(button->text()=="+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * (-1);
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    else if (button->text()=="%") {

        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{
   ui->pushButton_plus->setChecked(false);
   ui->pushButton_divide->setChecked(false);
   ui->pushButton_multiply->setChecked(false);
   ui->pushButton_divide->setChecked(false);

   ui->label->setText("");

   m_firstString = true;
}

void MainWindow::on_pushButton_equal_released()
{
    double labelNumber, secondNum;
   // QString newLabel;
    secondNum = ui->label->text().toDouble();
    double firstNum = getFirstNum();
    if(ui->pushButton_plus->isChecked())
    {

        labelNumber = firstNum + secondNum;
        m_newLabel = QString::number(labelNumber,'g',15);

        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_subtract->isChecked())
    {


        labelNumber = firstNum - secondNum;
        m_newLabel = QString::number(labelNumber,'g',15);

        ui->pushButton_subtract->setChecked(false);
    }
    else if (ui->pushButton_multiply->isChecked())
    {

        labelNumber = firstNum * secondNum;
        m_newLabel = QString::number(labelNumber,'g',15);

        ui->pushButton_multiply->setChecked(false);

    }
    else if (ui->pushButton_divide->isChecked())
    {
        if(secondNum == 0)
        {
            m_newLabel = "Error, Divided by 0";
        }
        else
        {
            labelNumber = firstNum / secondNum;
            m_newLabel = QString::number(labelNumber,'g',15);

            ui->pushButton_divide->setChecked(false);
        }


    }
   ui->label->setText(m_newLabel);

   ////reset value
   m_firstString = true;

}

void MainWindow:: binary_operation_pressed()
{
 QPushButton * button = (QPushButton*) sender();

  double firstNum = ui->label->text().toDouble();
  setFirstNum(firstNum);

     ////This function should be enabled in the constructor
    button->setChecked(true);

}

double MainWindow::getFirstNum()
{
    return m_fistNum;
}

void MainWindow::setFirstNum(double value)
{
    m_fistNum =value;
}











