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

//slot que recebe um sinal com o valor de fps alterado e mostra na tela
void MainWindow::changeFPS(double fps) {
    QString text = QString::number(fps);
    text += " FPS";
    ui->Lbl_FPSCounter->setText(text);
}
