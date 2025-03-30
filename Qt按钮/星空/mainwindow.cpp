#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QColor>
#include<QBrush>
#include<QPen>
#include<QPainterPath>
#include<QRandomGenerator>

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

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    //绘制背景
    QRadialGradient skyGradient(width()/2,height()/2,qMax(width(),height()));
    skyGradient.setColorAt(0,QColor(0,0,0)); //起始颜色
    skyGradient.setColorAt(1,QColor(0,100,255));
    painter.setBrush(skyGradient);
    painter.drawRect(rect()); //矩形

    for(int i=0;i<200;++i){

        //生成随机的x,y坐标

        int x=QRandomGenerator::global()->bounded(width());
        int y=QRandomGenerator::global()->bounded(height());

        //随机生成星星的大小
        int size=QRandomGenerator::global()->bounded(1,3);
        painter.setPen(Qt::white);
        painter.setBrush(Qt::white);
        painter.drawEllipse(x,y,size,size);


    }

    //绘制流星
    for(int i=0;i<10;++i){
        //生成x,y坐标
        int x1=QRandomGenerator::global()->bounded(width());
        int y1=QRandomGenerator::global()->bounded(height());

        int x2=QRandomGenerator::global()->bounded(width());
        int y2=QRandomGenerator::global()->bounded(height());

        //存储路径
        QPainterPath path;
        path.moveTo(x1,y1);
        path.lineTo(x2,y2);

        QPen pen(Qt::white);
        pen.setWidth(2);
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);
        painter.drawPath(path);
    }

    //绘制星球
    QPainterPath planetPath;
    planetPath.addEllipse(width()/2-100,height()/2-100,200,200);
    QRadialGradient planetGradient(width()/2,height()/2,100);
    planetGradient.setColorAt(0,QColor(0,150,200));
    planetGradient.setColorAt(1,QColor(0,100,150));
    QBrush planetBrush(planetGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(planetBrush);
    painter.drawPath(planetPath);

    //添加云层
    QPainterPath cloudPath;
    cloudPath.addEllipse(width()/2-80,height()/2-80,160,160);
    QRadialGradient cloudGradient(width()/2,height()/2,80);
    cloudGradient.setColorAt(0,QColor(255,255,255,100));
    cloudGradient.setColorAt(1,QColor(255,255,255,0));
    QBrush cloudBrush(cloudGradient);
    painter.setBrush(cloudBrush);
    painter.drawPath(cloudPath);

    //高光
    QPainterPath highlightPath;
    highlightPath.addEllipse(width()/2-50,height()/2-150,100,100);
    QBrush highlightBrush(QColor(255,255,255,150));
    painter.setBrush(highlightBrush);
    painter.drawPath(highlightPath);

    //光环
    QPainterPath ringPath;
    ringPath.addEllipse(width()/2-120,height()/2-120,240,240);
    QRadialGradient ringGradient(width()/2,height()/2,120);
    ringGradient.setColorAt(0,QColor(255,255,255,50));
    ringGradient.setColorAt(0.5, QColor(200, 200, 255, 50));
    ringGradient.setColorAt(1,QColor(255,255,255,0));
    QBrush ringBrush(ringGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(ringBrush);
    painter.drawPath(ringPath);

}
