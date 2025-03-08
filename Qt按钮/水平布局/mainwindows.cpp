//垂直布局
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QVBoxLayout>//垂直布局 vertical
#include<QHBoxLayout>//水平布局 horizontal

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建中心部件
    QWidget *centralWidget=new QWidget(this);
    setCentralWidget(centralWidget);
    //创建垂直布局的对象

    //QVBoxLayout*vBoxLayout=new QVBoxLayout();
    QHBoxLayout* hBoxLayout=new QHBoxLayout();
    QPushButton* button=new QPushButton("1",this);
    QPushButton* button2=new QPushButton("2",this);
    QPushButton* button3=new QPushButton("3",this);
    button->setFixedSize(100,50);
    button2->setFixedSize(100,50);
    button3->setFixedSize(100,50);
    //vBoxLayout->addWidget(button);
    //vBoxLayout->addWidget(button2);
    //vBoxLayout->addWidget(button3);
    //将垂直布局设计为中心布局
    //centralWidget->setLayout(vBoxLayout);
    hBoxLayout->addWidget(button);
    hBoxLayout->addWidget(button2);
    hBoxLayout->addWidget(button3);
    centralWidget->setLayout(hBoxLayout);


}

MainWindow::~MainWindow()
{
    delete ui;
}
