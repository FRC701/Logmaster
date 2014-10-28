/********************************************************************************
** Form generated from reading UI file 'rfidreader.ui'
**
** Created: Wed Jan 22 19:48:49 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RFIDREADER_H
#define UI_RFIDREADER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RFIDReader
{
public:
    QWidget *centralWidget;
    QLineEdit *tagEdit;
    QLineEdit *nameEdit;
    QLineEdit *statusEdit;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *hoursEdit;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RFIDReader)
    {
        if (RFIDReader->objectName().isEmpty())
            RFIDReader->setObjectName(QString::fromUtf8("RFIDReader"));
        RFIDReader->resize(480, 272);
        centralWidget = new QWidget(RFIDReader);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tagEdit = new QLineEdit(centralWidget);
        tagEdit->setObjectName(QString::fromUtf8("tagEdit"));
        tagEdit->setGeometry(QRect(180, 20, 151, 23));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(180, 60, 151, 23));
        statusEdit = new QLineEdit(centralWidget);
        statusEdit->setObjectName(QString::fromUtf8("statusEdit"));
        statusEdit->setGeometry(QRect(180, 100, 151, 23));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(30, 180, 64, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 81, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 60, 71, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 100, 91, 16));
        hoursEdit = new QLineEdit(centralWidget);
        hoursEdit->setObjectName(QString::fromUtf8("hoursEdit"));
        hoursEdit->setGeometry(QRect(180, 140, 151, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 140, 131, 16));
        RFIDReader->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RFIDReader);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 20));
        RFIDReader->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RFIDReader);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RFIDReader->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RFIDReader);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RFIDReader->setStatusBar(statusBar);

        retranslateUi(RFIDReader);

        QMetaObject::connectSlotsByName(RFIDReader);
    } // setupUi

    void retranslateUi(QMainWindow *RFIDReader)
    {
        RFIDReader->setWindowTitle(QApplication::translate("RFIDReader", "RFIDReader", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RFIDReader", "Tag", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RFIDReader", "Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RFIDReader", "Status", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RFIDReader", "Earned Hours", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RFIDReader: public Ui_RFIDReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RFIDREADER_H
