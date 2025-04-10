#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLinearGradient>
#include<QPen>
#include<QGraphicsDropShadowEffect>
#include<QFont>

//烟花粒子的实现
FireworksParticle::FireworksParticle(QPointF startPos,QColor color,QGraphicsScene*scene)
    :QGraphicsEllipseItem(-2,-2,4,4),m_scene(scene)
{
    setPos(startPos);
    setBrush(color);
    setPen(Qt::NoPen);
    m_scene->addItem(this);

    //随机生成速度
    m_vx=QRandomGenerator::global()->bounded(-5,5);
    m_vy=QRandomGenerator::global()->bounded(-15,5);

    m_timer=new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&FireworksParticle::updatePosition);
    m_timer->start(30);
}

void FireworksParticle::updatePosition()
{
    m_vy+=0.5;
    moveBy(m_vx,m_vy);
    if(pos().y()>m_scene->height() || pos().x()<0 || pos().x()>m_scene->width())
    {
        m_scene->removeItem(this);
        delete this;
    }
}

//自定义视图
CustomView::CustomView(QGraphicsScene *scene,QWidget *parent)
    :QGraphicsView(scene,parent),m_scene(scene){}

void CustomView::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton)
    {
        QPointF clickPos=mapToScene(event->pos());
        createFireworks(clickPos);
    }
    QGraphicsView::mousePressEvent(event);
}

void CustomView::createFireworks(const QPointF &pos){
    QColor colors[]={Qt::red,Qt::green,Qt::blue,Qt::yellow,Qt::magenta,Qt::cyan};
    for(int i=0;i<50;++i){
        QColor color=colors[QRandomGenerator::global()->bounded(6)];
        new FireworksParticle(pos,color,m_scene);
    }
}

//绘制红包
void drawRedEnvelope(QGraphicsScene*scene,qreal x,qreal y){
    QPen pen(Qt::NoPen);
    QBrush brush(Qt::red);
    QRectF envelopeRect(x,y,120,180);
    QGraphicsRectItem*envelope=scene->addRect(envelopeRect,pen,brush);

    QLinearGradient gradient(envelopeRect.topLeft(),envelopeRect.bottomRight());
    gradient.setColorAt(0,QColor(180,0,0));
    gradient.setColorAt(1,Qt::red);
    envelope->setBrush(gradient);

    QFont textFont("Arial",36,QFont::Bold);
    QGraphicsTextItem*text=scene->addText("福",textFont);
    text->setDefaultTextColor(Qt::yellow);
    text->setPos(x+(envelopeRect.width()-text->boundingRect().width())/2,
                 y+(envelopeRect.height()-text->boundingRect().height())/2);

}

//灯笼
void drawLantern(QGraphicsScene *scene,qreal x,qreal y)
{
    QPen pen(Qt::NoPen);
    QBrush brush(Qt::red);
    QRectF lanternRect(x,y,100,150);
    QGraphicsEllipseItem *lantern=scene->addEllipse(lanternRect,pen,brush);

    QLinearGradient gradient(lanternRect.topLeft(),lanternRect.bottomRight());
    gradient.setColorAt(0,QColor(180,0,0));
    gradient.setColorAt(1,Qt::red);
    lantern->setBrush(gradient);

    QPen linePen(Qt::yellow,4);
    scene->addLine(x+lanternRect.width()/2,y,x+lanternRect.width()/2,y-30,linePen);
    scene->addLine(x+lanternRect.width()/2,y+lanternRect.height(),
                   x+lanternRect.width()/2,y+lanternRect.height()+30,linePen);
}

void drawFirecrackers(QGraphicsScene *scene,qreal x,qreal y){
    QPen pen(Qt::NoPen);
    QBrush brush(Qt::red);
    for(int i=0;i<6;++i){
        QRectF crackerRect(x,y+i*35,25,30);
        QGraphicsRectItem *cracker=scene->addRect(crackerRect,pen,brush);

        QLinearGradient gradient(crackerRect.topLeft(),crackerRect.bottomRight());
        gradient.setColorAt(0,QColor(180,0,0));
        gradient.setColorAt(1,Qt::red);
        cracker->setBrush(gradient);

        QPen fusePen(Qt::yellow,2);
        scene->addLine(x+crackerRect.width(),y+i*35+crackerRect.height()/2,
                        x+crackerRect.width()+15,y+i*35+crackerRect.height()/2,fusePen);
    }
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_scene=new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,800,600);
    m_view=new CustomView(m_scene,this);
    m_view->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(m_view);
    setWindowTitle("2025新年快乐");
    resize(800,600);

    QLinearGradient backgroundGradient(0,0,0,m_scene->height());
    backgroundGradient.setColorAt(0,QColor(255,220,220));
    backgroundGradient.setColorAt(1,QColor(200,0,0));
    m_scene->setBackgroundBrush(backgroundGradient);

    QFont customFont("Arial",60,QFont::ExtraBold);
    QGraphicsTextItem *textItem=m_scene->addText("2025新年快乐！",customFont);
    textItem->setDefaultTextColor(Qt::yellow);
    textItem->setPos((m_scene->width()-textItem->boundingRect().width())/2,
                     (m_scene->height()-textItem->boundingRect().height())/2);
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(Qt::red);
    shadow->setOffset(10);
    textItem->setGraphicsEffect(shadow);
    textItem->setZValue(10);

    drawRedEnvelope(m_scene,30,50);
    drawFirecrackers(m_scene,600,80);
    drawLantern(m_scene,350,20);

}

MainWindow::~MainWindow()
{
    delete ui;
}
