/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actAbrir;
    QWidget *widPrincipal;
    QPushButton *btnSair;
    QCheckBox *ckbCorFundo;
    GLWidget *widget;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1097, 690);
        actAbrir = new QAction(MainWindow);
        actAbrir->setObjectName(QString::fromUtf8("actAbrir"));
        QFont font;
        font.setPointSize(12);
        actAbrir->setFont(font);
        widPrincipal = new QWidget(MainWindow);
        widPrincipal->setObjectName(QString::fromUtf8("widPrincipal"));
        btnSair = new QPushButton(widPrincipal);
        btnSair->setObjectName(QString::fromUtf8("btnSair"));
        btnSair->setGeometry(QRect(870, 610, 75, 23));
        btnSair->setFont(font);
        ckbCorFundo = new QCheckBox(widPrincipal);
        ckbCorFundo->setObjectName(QString::fromUtf8("ckbCorFundo"));
        ckbCorFundo->setGeometry(QRect(870, 590, 161, 21));
        ckbCorFundo->setFont(font);
        ckbCorFundo->setChecked(true);
        widget = new GLWidget(widPrincipal);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 831, 601));
        MainWindow->setCentralWidget(widPrincipal);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1097, 27));
        menubar->setFont(font);
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuArquivo->setFont(font);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actAbrir);

        retranslateUi(MainWindow);
        QObject::connect(btnSair, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(ckbCorFundo, SIGNAL(toggled(bool)), widget, SLOT(toggleBackgroundColor(bool)));
        QObject::connect(actAbrir, SIGNAL(triggered()), widget, SLOT(showFileOpenDialog()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Visualizador 3D", nullptr));
        actAbrir->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        btnSair->setText(QCoreApplication::translate("MainWindow", "Sair", nullptr));
        ckbCorFundo->setText(QCoreApplication::translate("MainWindow", "Trocar cor de fundo", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("MainWindow", "Arquivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
