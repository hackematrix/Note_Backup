#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout *layout=new QVBoxLayout;
    
    progressBar=new QProgressBar(this);
    progressBar->setMinimum(0); //设置最小值
    progressBar->setMaximum(100); //设置最大值
    progressBar->setValue(0);
    progressBar->setFormat("%p%"); //设置百分比
    progressBar->setTextVisible(true);
    layout->addWidget(progressBar);

    startButton=new QPushButton("开始",this);
    layout->addWidget(startButton);

    QWidget *centralWidget=new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    timer=new QTimer(this);

    connect(startButton,&QPushButton::clicked,this,&MainWindow::onStartButtonClicked);
    connect(timer,&QTimer::timeout,this,&MainWindow::onTimerTimeout);

}//构造函数

MainWindow::~MainWindow() {}

void MainWindow::onStartButtonClicked(){
    if(timer->isActive()){
        timer->stop();
        startButton->setText("开始");
    }
    else{
        currentValue=0;
        progressBar->setValue(0);
        timer->start(100);
        startButton->setText("停止");
    }
}

void MainWindow::onTimerTimeout(){
    currentValue+=1;
    progressBar->setValue(currentValue);
    if(currentValue>=progressBar->maximum()){
        timer->stop();
        startButton->setText("开始");
    }
}
