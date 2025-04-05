#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QPainterPath>
#include<QRandomGenerator> //随机数
#include<QLinearGradient>
#include<QPropertyAnimation>
#include<QMenu>
#include<QInputDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,600);
    scene=new QGraphicsScene(this);
    view =new QGraphicsView(scene,this);
    view->setGeometry(0,0,800,600);
    view->setRenderHint(QPainter::Antialiasing); //抗锯齿
    view->setSceneRect(0,0,800,600);

    //绘制天空
    QLinearGradient skyGradient(0,0,0,300);
    skyGradient.setColorAt(0,QColor(135,206,250));
    skyGradient.setColorAt(1,QColor(240,248,255));
    QGraphicsRectItem *skyItem=new QGraphicsRectItem(0,0,800,300);
    skyItem->setBrush(QBrush(skyGradient));
    scene->addItem(skyItem);

    //绘制大海
    QLinearGradient seaGradient(0,300,0,600);
    seaGradient.setColorAt(0,QColor(30,144,255));
    seaGradient.setColorAt(1,QColor(0,0,128));
    QGraphicsRectItem *seaItem=new QGraphicsRectItem(0,300,800,300);
    seaItem->setBrush(QBrush(seaGradient));
    scene->addItem(seaItem);

    //绘制沙滩
    QGraphicsRectItem *beachItem=new QGraphicsRectItem(0,500,800,100);
    beachItem->setBrush(QBrush(QColor(255,228,181)));
    scene->addItem(beachItem);

    //绘制太阳
    sunItem=new QGraphicsEllipseItem(650,50,100,100);
    sunItem->setBrush(QBrush(Qt::yellow));
    sunItem->setPen(Qt::NoPen);
    scene->addItem(sunItem);

    //创建云朵
    for(int i=0;i<3;i++){
        QGraphicsEllipseItem *cloud=new QGraphicsEllipseItem(QRandomGenerator::global()->bounded(100),QRandomGenerator::global()->bounded(100),100,50);
        cloud->setBrush(QBrush(Qt::white));
        cloud->setPen(Qt::NoPen);
        scene->addItem(cloud);
        cloudItems.append(cloud);
    }

    //创建椰子树
    QPolygonF palmTreeShape;
    palmTreeShape<<QPointF(20,500)<<QPointF(70,100)<<QPointF(120,500);
    palmTreeItem=new QGraphicsPolygonItem(palmTreeShape);
    QLinearGradient palmTreeGradient(70,100,70,500);
    palmTreeGradient.setColorAt(0,QColor(50,205,50));
    palmTreeGradient.setColorAt(1,QColor(0,100,0));
    palmTreeItem->setBrush(QBrush(palmTreeGradient));
    palmTreeItem->setPen(Qt::NoPen);
    palmTreeItem->setFlags(QGraphicsItem::ItemIsMovable); //设置移动
    palmTreeItem->setCursor(Qt::PointingHandCursor);
    scene->addItem(palmTreeItem);



}

MainWindow::~MainWindow()
{
    delete ui;
}

//鼠标按下处理函数

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(sunItem->contains(event->pos())){
        //判断是否为左键
        if(event->button()==Qt::LeftButton){
            QPoint localPos=event->pos();
            qDebug()<<"local position:"<<localPos;
            sunItem->setBrush(QColor(255,215,0));

        }
        else if(event->button()==Qt::MiddleButton){
            sunItem->setBrush(QColor(255,165,0));
        }
        else if(event->button()==Qt::RightButton){

            QMenu menu(this);
            QAction *moveSunAction=menu.addAction("move");
            connect(moveSunAction,&QAction::triggered,this,&MainWindow::onMoveSunTriggered);
            menu.exec(event->globalPos());
        }
    }
}

void MainWindow::onMoveSunTriggered(){
    bool ok;
    double distance=QInputDialog::getDouble(this,"Move Sun","Enter the distance to move the sun",0,-100,100,1,&ok);
    if(ok){
        sunItem->moveBy(distance,0);
    }
}
