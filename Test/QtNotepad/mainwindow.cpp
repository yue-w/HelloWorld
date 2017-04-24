#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Remove the boundary
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{

    m_file_path = "";

    ////reset text
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open the file", QDir::homePath() );
    QFile file(file_name);

    ////pass the file path to the globle value. Use for "save file" funciton.
    m_file_path = file_name;
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
//    if(!file.open(QFile::ReadOnly | QFile::Text))
//    {
//        QMessageBox::warning(this, "..", "File not open");
//        return;
//    }
//    else
//    {
//        QTextStream in(&file);
//        QString text = in.readAll();
//        ui->textEdit->setText(text);
//        file.close();

//    }
}

void MainWindow::on_actionSave_triggered()
{

   // QString file_name = QFileDialog::getSaveFileName(this, "Open the file", QDir::homePath() );

    //// if this is a new file and has not been saved before, choose a path.
    if(m_file_path =="")
    {
        QString file_name = QFileDialog::getSaveFileName(this, "Open the file", QDir::homePath() );
        ////pass the file path to the globle value. Use for "save file" funciton.
        m_file_path = file_name;
    }
    QFile file(m_file_path);

    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

            //    if(!file.open(QFile::WriteOnly | QFile::Text))
            //    {
            //        QMessageBox::warning(this, "..", "File not open");
            //        return;
            //    }
            //    else
            //    {
            //        QTextStream out(&file);
            //        QString text = ui->textEdit->toPlainText();
            //        out<<text;
            //        file.flush();
            //        file.close();

            //    }

}

void MainWindow::on_actionSave_as_triggered()
{

    QString file_name = QFileDialog::getSaveFileName(this, "Open the file", QDir::homePath() );
    QFile file(file_name);

    ////pass the file path to the globle value. Use for "save file" funciton.
    m_file_path = file_name;


//    if(!file.open(QFile::WriteOnly | QFile::Text))
//    {
//        QMessageBox::warning(this, "..", "File not open");
//        return;
//    }
//    else
//    {
//        QTextStream out(&file);
//        QString text = ui->textEdit->toPlainText();
//        out<<text;
//        file.flush();
//        file.close();

//    }

    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();

}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();

}

void MainWindow::on_actionUndo_triggered()
{

   // ui->textEdit->undoAvailable();
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString about_text ="";
    //about_text= "Auther: Yue Wang\n";
    about_text +="TestNotepad\n";
    about_text +="Date : 23/4/2017\n";
    about_text+="Email: yuewang@protonmail.com\n";
    QMessageBox::about(this, "About", about_text);
}
