#include "textfinder.h"
#include "ui_textfinder.h"
#include <QFile>
#include <QTextStream>

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::on_findButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}

void TextFinder::loadTextFile()
{
   //QFile inputFile("W:\Programming\CPP\input.txt");
    QFile inputFile("..\input.txt");



    if (!inputFile.open(QIODevice::ReadOnly))//failed to open
    {
        ui->textEdit->setPlainText("Failed to open the file");
    }
    else
    {
        QTextStream in(&inputFile);
        QString line = in.readAll();
        inputFile.close();
        ui->textEdit->setPlainText(line);
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
    }



}
