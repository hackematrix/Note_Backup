#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>

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

void MainWindow::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setPen(QPen(Qt::red,2));
    painter.drawLine(50,50,200,200);
    painter.drawEllipse(100,100,200,200);
}
