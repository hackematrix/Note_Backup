#include "mainwindow.h"
#include<QBrush>
#include<QPen>
#include<QFont>
#include<QPainter>
#include<QLinearGradient>
#include<QRadialGradient>
#include<QPixmap>
#include<Qt>

MainWindow::MainWindow(QWidget *parent):QGraphicsView(parent)
{
    scene=new QGraphicsScene(this);
    setScene(scene);
    createScene();
}



MainWindow::~MainWindow() {
    delete scene;
}

void MainWindow::createScene(){
    QLinearGradient skyGradient(0,0,0,400);
    skyGradient.setColorAt(0,QColor(133,206,235));
    skyGradient.setColorAt(1,QColor(255,255,255));
    scene->setBackgroundBrush(QBrush(skyGradient));

    //创建太阳
    QGraphicsEllipseItem *sun=new QGraphicsEllipseItem(400,50,100,100);
    QRadialGradient sunGradient(450,100,50);
    sunGradient.setColorAt(0,QColor(255,255,153));
    sunGradient.setColorAt(1,QColor(255,215,0));
    sun->setBrush(QBrush(sunGradient));
    sun->setPen(QPen(Qt::transparent));
    scene->addItem(sun);

    //创建草地
    QGraphicsRectItem *grass=new QGraphicsRectItem(0,300,800,200);
    QLinearGradient grassGradient(0,300,0,500);
    grassGradient.setColorAt(0,QColor(34,139,34));
    grassGradient.setColorAt(1,QColor(0,128,0));
    grass->setBrush(QBrush(grassGradient));
    grass->setPen(QPen(Qt::transparent));
    scene->addItem(grass);

    //云
    QGraphicsEllipseItem *cloud1=new QGraphicsEllipseItem(100,100,80,50);
    cloud1->setBrush(QBrush(QColor(245,245,245)));
    cloud1->setPen(QPen(Qt::transparent));

    QGraphicsEllipseItem *cloud2=new QGraphicsEllipseItem(130,80,80,50);
    cloud2->setBrush(QBrush(QColor(245,245,245)));
    cloud2->setPen(QPen(Qt::transparent));

    QGraphicsEllipseItem*cloud3=new QGraphicsEllipseItem(160,100,80,50);
    cloud3->setBrush(QBrush(QColor(245,245,245)));
    cloud3->setPen(QPen(Qt::transparent));

    scene->addItem(cloud1);
    scene->addItem(cloud2);
    scene->addItem(cloud3);

    //房子
    QGraphicsRectItem*houseBase=new QGraphicsRectItem(500,250,200,150);
    houseBase->setBrush(QBrush(QColor(255,228,196)));
    houseBase->setPen(QPen(QColor(160,82,45),2));
    scene->addItem(houseBase);

    //房子的门
    QGraphicsRectItem*houseDoor=new QGraphicsRectItem(580,330,40,70);
    houseDoor->setBrush(QBrush(QColor(139,69,19)));
    houseDoor->setPen(QPen(QColor(139,69,19),2));
    scene->addItem(houseDoor);

    //窗口
    QGraphicsRectItem*houseWindow1=new QGraphicsRectItem(520,270,40,40);
    houseWindow1->setBrush(QBrush(QColor(255,255,224)));
    houseWindow1->setPen(QPen(QColor(0,0,0),2));
    scene->addItem(houseWindow1);

    QGraphicsRectItem*houseWindow2=new QGraphicsRectItem(640,270,40,40);
    houseWindow2->setBrush(QBrush(QColor(255,255,224)));
    houseWindow2->setPen(QPen(QColor(0,0,0),2));
    scene->addItem(houseWindow2);

    //小路
    QGraphicsRectItem*path=new QGraphicsRectItem(100,350,600,50);
    QLinearGradient pathGradient(0,350,0,400);
    pathGradient.setColorAt(0,QColor(139,69,19));
    pathGradient.setColorAt(1,QColor(210,180,140));
    path->setBrush(QBrush(pathGradient));
    path->setPen(QPen(Qt::transparent));
    scene->addItem(path);

    //石头
    QGraphicsEllipseItem*stone1=new QGraphicsEllipseItem(200,350,30,30);
    stone1->setBrush(QBrush(QColor(128,128,128)));
    stone1->setPen(QPen(Qt::transparent));
    scene->addItem(stone1);

    QGraphicsEllipseItem*stone2=new QGraphicsEllipseItem(300,370,40,40);
    stone2->setBrush(QBrush(QColor(128,128,128)));
    stone2->setPen(QPen(Qt::transparent));
    scene->addItem(stone2);


    QGraphicsEllipseItem*stone3=new QGraphicsEllipseItem(450,360,35,35);
    stone3->setBrush(QBrush(QColor(128,128,128)));
    stone3->setPen(QPen(Qt::transparent));
    scene->addItem(stone3);

}
