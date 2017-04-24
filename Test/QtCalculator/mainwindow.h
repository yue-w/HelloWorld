#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double m_fistNum;
    QString m_newLabel;

    ////used to control when multi-digit number and operator are typed.
    bool m_firstString;

private slots:
    void digit_pressed();
    void on_pushButton_decimal_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equal_released();
    void binary_operation_pressed();

public:
    double getFirstNum();
    void setFirstNum(double value);
};

#endif // MAINWINDOW_H
