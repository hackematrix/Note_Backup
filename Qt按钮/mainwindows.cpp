#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton> //按钮的头文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置一个按钮
    QPushButton*button=new QPushButton("01",this);
    //设置按钮的大小，前两个参数表示x和y坐标，后两个参数表示宽和高
    button->setGeometry(50,50,150,100);
    button->setStyleSheet("color:yellow;"
                          "background-color:lightblue;"
                          "font-size:30px;");
    button->setFlat(false);
    button->setVisible(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}
