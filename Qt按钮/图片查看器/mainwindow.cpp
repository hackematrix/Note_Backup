#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVBoxLayout>
#include<QPalette>
#include<QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageLabel=new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter); //居中对齐
    imageLabel->setStyleSheet("border:1px solid #ccc;border-radius:6px;");

    openButton=new QPushButton("打开图片",this);
    openButton->setFixedHeight(35);
    openButton->setStyleSheet("background-color:#28a745; color:white; padding:8px 16px;border-radius:6px;");
    openButton->setCursor(Qt::PointingHandCursor); //光标设置为手形

    QVBoxLayout*mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(openButton);

    QWidget*centralWidget=new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    QPalette palette=this->palette();
    palette.setColor(QPalette::Window,QColor(245,245,245));//灰色
    this->setPalette(palette);

    QFont font("Arial 12");
    this->setFont(font);

    connect(openButton,&QPushButton::clicked,this,&MainWindow::onOpenButtonClicked);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenButtonClicked(){
    QString filePath=QFileDialog::getOpenFileName(this,"选择图片文件","D:\\piture","图片文件 (*.png *.jpg *.jpeg)");
    if(!filePath.isEmpty()){
        QPixmap pixmap(filePath);
        if(!pixmap.isNull()){
            imageLabel->setPixmap(pixmap.scaled(imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
        }
    }
}
