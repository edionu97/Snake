/********************************************************************************
** Form generated from reading UI file 'chesie.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESIE_H
#define UI_CHESIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chesieClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chesieClass)
    {
        if (chesieClass->objectName().isEmpty())
            chesieClass->setObjectName(QStringLiteral("chesieClass"));
        chesieClass->resize(600, 400);
        menuBar = new QMenuBar(chesieClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        chesieClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chesieClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        chesieClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(chesieClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chesieClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(chesieClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        chesieClass->setStatusBar(statusBar);

        retranslateUi(chesieClass);

        QMetaObject::connectSlotsByName(chesieClass);
    } // setupUi

    void retranslateUi(QMainWindow *chesieClass)
    {
        chesieClass->setWindowTitle(QApplication::translate("chesieClass", "chesie", 0));
    } // retranslateUi

};

namespace Ui {
    class chesieClass: public Ui_chesieClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESIE_H
