/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_4;
    QLineEdit *lineEdit_objectFunction;
    QLabel *label_5;
    QLineEdit *lineEdit_constraintFunction1;
    QLabel *label_6;
    QLineEdit *lineEdit_constraintFunction2;
    QLineEdit *lineEdit_MaxIterationTimes;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLabel *label_10;
    QLineEdit *lineEdit_MaxIterationTimes_2;
    QLabel *label_11;
    QLineEdit *lineEdit_MaxIterationTimes_3;
    QPushButton *pushButton_optimize;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_variable1;
    QLineEdit *lineEdit_variable2;
    QLineEdit *lineEdit_variable3;
    QLineEdit *lineEdit_variable4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_lowerbound1;
    QLineEdit *lineEdit_lowerbound2;
    QLineEdit *lineEdit_lowerbound3;
    QLineEdit *lineEdit_lowerbound4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_upperbound1;
    QLineEdit *lineEdit_upperbound2;
    QLineEdit *lineEdit_upperbound3;
    QLineEdit *lineEdit_upperbound4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEdit_variable1_output;
    QLineEdit *lineEdit_variable2_output;
    QLineEdit *lineEdit_variable3_output;
    QLineEdit *lineEdit_variable4_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(826, 562);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 250, 81, 16));
        lineEdit_objectFunction = new QLineEdit(centralWidget);
        lineEdit_objectFunction->setObjectName(QStringLiteral("lineEdit_objectFunction"));
        lineEdit_objectFunction->setGeometry(QRect(130, 250, 291, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 300, 121, 16));
        lineEdit_constraintFunction1 = new QLineEdit(centralWidget);
        lineEdit_constraintFunction1->setObjectName(QStringLiteral("lineEdit_constraintFunction1"));
        lineEdit_constraintFunction1->setGeometry(QRect(140, 300, 291, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 350, 121, 16));
        lineEdit_constraintFunction2 = new QLineEdit(centralWidget);
        lineEdit_constraintFunction2->setObjectName(QStringLiteral("lineEdit_constraintFunction2"));
        lineEdit_constraintFunction2->setGeometry(QRect(140, 350, 291, 20));
        lineEdit_MaxIterationTimes = new QLineEdit(centralWidget);
        lineEdit_MaxIterationTimes->setObjectName(QStringLiteral("lineEdit_MaxIterationTimes"));
        lineEdit_MaxIterationTimes->setGeometry(QRect(170, 160, 113, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 160, 111, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 210, 111, 16));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 210, 113, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(630, 20, 81, 16));
        lineEdit_MaxIterationTimes_2 = new QLineEdit(centralWidget);
        lineEdit_MaxIterationTimes_2->setObjectName(QStringLiteral("lineEdit_MaxIterationTimes_2"));
        lineEdit_MaxIterationTimes_2->setGeometry(QRect(710, 20, 113, 20));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(630, 80, 81, 16));
        lineEdit_MaxIterationTimes_3 = new QLineEdit(centralWidget);
        lineEdit_MaxIterationTimes_3->setObjectName(QStringLiteral("lineEdit_MaxIterationTimes_3"));
        lineEdit_MaxIterationTimes_3->setGeometry(QRect(710, 80, 113, 20));
        pushButton_optimize = new QPushButton(centralWidget);
        pushButton_optimize->setObjectName(QStringLiteral("pushButton_optimize"));
        pushButton_optimize->setGeometry(QRect(150, 420, 75, 23));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 419, 121));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_variable1 = new QLineEdit(widget);
        lineEdit_variable1->setObjectName(QStringLiteral("lineEdit_variable1"));

        verticalLayout->addWidget(lineEdit_variable1);

        lineEdit_variable2 = new QLineEdit(widget);
        lineEdit_variable2->setObjectName(QStringLiteral("lineEdit_variable2"));

        verticalLayout->addWidget(lineEdit_variable2);

        lineEdit_variable3 = new QLineEdit(widget);
        lineEdit_variable3->setObjectName(QStringLiteral("lineEdit_variable3"));

        verticalLayout->addWidget(lineEdit_variable3);

        lineEdit_variable4 = new QLineEdit(widget);
        lineEdit_variable4->setObjectName(QStringLiteral("lineEdit_variable4"));

        verticalLayout->addWidget(lineEdit_variable4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_lowerbound1 = new QLineEdit(widget);
        lineEdit_lowerbound1->setObjectName(QStringLiteral("lineEdit_lowerbound1"));

        verticalLayout_2->addWidget(lineEdit_lowerbound1);

        lineEdit_lowerbound2 = new QLineEdit(widget);
        lineEdit_lowerbound2->setObjectName(QStringLiteral("lineEdit_lowerbound2"));

        verticalLayout_2->addWidget(lineEdit_lowerbound2);

        lineEdit_lowerbound3 = new QLineEdit(widget);
        lineEdit_lowerbound3->setObjectName(QStringLiteral("lineEdit_lowerbound3"));

        verticalLayout_2->addWidget(lineEdit_lowerbound3);

        lineEdit_lowerbound4 = new QLineEdit(widget);
        lineEdit_lowerbound4->setObjectName(QStringLiteral("lineEdit_lowerbound4"));

        verticalLayout_2->addWidget(lineEdit_lowerbound4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        lineEdit_upperbound1 = new QLineEdit(widget);
        lineEdit_upperbound1->setObjectName(QStringLiteral("lineEdit_upperbound1"));

        verticalLayout_3->addWidget(lineEdit_upperbound1);

        lineEdit_upperbound2 = new QLineEdit(widget);
        lineEdit_upperbound2->setObjectName(QStringLiteral("lineEdit_upperbound2"));

        verticalLayout_3->addWidget(lineEdit_upperbound2);

        lineEdit_upperbound3 = new QLineEdit(widget);
        lineEdit_upperbound3->setObjectName(QStringLiteral("lineEdit_upperbound3"));

        verticalLayout_3->addWidget(lineEdit_upperbound3);

        lineEdit_upperbound4 = new QLineEdit(widget);
        lineEdit_upperbound4->setObjectName(QStringLiteral("lineEdit_upperbound4"));

        verticalLayout_3->addWidget(lineEdit_upperbound4);


        horizontalLayout->addLayout(verticalLayout_3);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(450, 20, 135, 119));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        lineEdit_variable1_output = new QLineEdit(widget1);
        lineEdit_variable1_output->setObjectName(QStringLiteral("lineEdit_variable1_output"));

        verticalLayout_4->addWidget(lineEdit_variable1_output);

        lineEdit_variable2_output = new QLineEdit(widget1);
        lineEdit_variable2_output->setObjectName(QStringLiteral("lineEdit_variable2_output"));

        verticalLayout_4->addWidget(lineEdit_variable2_output);

        lineEdit_variable3_output = new QLineEdit(widget1);
        lineEdit_variable3_output->setObjectName(QStringLiteral("lineEdit_variable3_output"));

        verticalLayout_4->addWidget(lineEdit_variable3_output);

        lineEdit_variable4_2 = new QLineEdit(widget1);
        lineEdit_variable4_2->setObjectName(QStringLiteral("lineEdit_variable4_2"));

        verticalLayout_4->addWidget(lineEdit_variable4_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 826, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Object Function", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Constraint Function One", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Constraint Function Two", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Max. Iteration Times", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Accuracy", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Iteration Times", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Stop Reason", Q_NULLPTR));
        pushButton_optimize->setText(QApplication::translate("MainWindow", "Optimize", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Variable Name", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Lower Bound", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Upper Bound", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Output Value", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
