#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QMessageBox>

//槽函数,响应特定信号事件
//void onButtonClicked(){
   // QMessageBox::information(nullptr,"提示","你点击了按钮");

//}//nullptr 表示提示框没有父窗口,提示框的标题,提示框的内容

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //创建按钮
    QPushButton *button=new QPushButton("01",this);
    //设计按钮的位置,前两个参数表示x,y,后两个参数表示宽和高
    button->setGeometry(50,50,150,100);
    button->setStyleSheet("color:yellow;"
                          "background-color:lightblue;"
                          "font-size:30px;");
    button->setFlat(false);
    button->setVisible(true);
    //connect(button,&QPushButton::clicked,onButtonClicked);
    connect(button,&QPushButton::clicked,[]{
        QMessageBox::information(nullptr,"提示","你点击了按钮(2)");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
