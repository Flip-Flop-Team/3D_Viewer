#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeFPS(double fps) {
    QString text = QString::number(fps);
    text += " FPS";
    ui->Lbl_FPSCounter->setText(text);
}
