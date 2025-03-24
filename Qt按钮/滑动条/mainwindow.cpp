#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout *layout=new QVBoxLayout;//创建垂直布局
    slider=new QSlider(Qt::Horizontal,this); //创建滑块并设置方向为水平
    slider->setMinimum(0); //滑块最小值
    slider->setMaximum(100);//滑块最大值
    slider->setValue(50); //滑块初始值
    layout->addWidget(slider);

    valueLabel=new QLabel(QString::number(slider->value()),this); //添加标签
    valueLabel->setAlignment(Qt::AlignCenter); //居中对齐
    layout->addWidget(valueLabel);

    QWidget*centralWidget=new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(slider,&QSlider::valueChanged,this,&MainWindow::onSliderValueChanged); //连接槽函数

//构造函数的实现
}
MainWindow::~MainWindow() {}

//槽函数
void MainWindow::onSliderValueChanged(int value)
{
    valueLabel->setText(QString::number(value));
}
