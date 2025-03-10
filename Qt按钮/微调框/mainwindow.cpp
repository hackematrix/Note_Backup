#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget=new QWidget(this);
    setCentralWidget(centralWidget);

    layout=new QVBoxLayout(centralWidget);
    layout->setSpacing(20);
    layout->setContentsMargins(20,20,20,20);

    spinBox=new QSpinBox(centralWidget);
    spinBox->setMinimum(0);
    spinBox->setMaximum(100);
    spinBox->setSingleStep(1);
    spinBox->setValue(50);
    spinBox->setMinimumSize(200,40);
    spinBox->setStyleSheet("QSpinBox {font-size:16px;padding:5px; border:1px solid #ccc;border-radius:5px;}");
    layout->addWidget(spinBox);

    spinLabel=new QLabel(QString("整数当前值:%1").arg(spinBox->value()),centralWidget);
    spinLabel->setStyleSheet("QLabel {font-size:16px;}");
    layout->addWidget(spinLabel);

    doubleSpinBox=new QDoubleSpinBox(centralWidget);
    doubleSpinBox->setMinimum(0.0);
    doubleSpinBox->setMaximum(10.0);
    doubleSpinBox->setSingleStep(0.1);
    doubleSpinBox->setDecimals(1);
    doubleSpinBox->setValue(5.0);
    doubleSpinBox->setMinimumSize(200,40);
    doubleSpinBox->setStyleSheet("QDoubleSpinBox {font-size:16px;padding:5px;border:1px soild #ccc;border-radius:5px;}");
    layout->addWidget(doubleSpinBox);

    doubleSpinLabel=new QLabel(QString("浮点数当前值:%1").arg(doubleSpinBox->value()),centralWidget);
    doubleSpinLabel->setStyleSheet("QLabel {font-size:16px;}");

    connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(onSpinBoxValueChanged(int)));
    connect(doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(onDoubleSpinBoxValueChanged(double)));

    this->setStyleSheet("QMainWindow{background-color:#f0f0f0;}");


}

MainWindow::~MainWindow() {
    delete spinBox;
    delete doubleSpinBox;
    delete spinLabel;
    delete doubleSpinLabel;
    delete layout;
    delete centralWidget;
}

void MainWindow::onSpinBoxValueChanged(int value){
    spinLabel->setText(QString("整数当前值:%1").arg(value));
}

void MainWindow::onDoubleSpinBoxValueChanged(double value){
    spinLabel->setText(QString("浮点数当前值:%1").arg(value));
}
