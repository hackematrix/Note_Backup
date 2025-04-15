#include "mainwindow.h"
#include<QPainter>
#include<QPen>
#include<QBrush>
#include<QRandomGenerator>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),direction(1),gameOver(false)
{
    setFixedSize(400,400);
    setFocusPolicy(Qt::StrongFocus);
    snake.append(QPoint(100,100));
    snake.append(QPoint(80,100));
    snake.append(QPoint(60,100));
    spawnFood();
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::updateGame);
    timer->start(100);
}

MainWindow::~MainWindow() {
    delete timer;
}

void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    QPen pen(Qt::black,2);
    QBrush brush(Qt::green);
    painter.setPen(pen);
    painter.setBrush(brush);
    if(gameOver){
        painter.drawText(rect(),Qt::AlignCenter,"Game Over");
        return;
    }
    drawSnake();
    drawFood();
}

void MainWindow::keyPressEvent(QKeyEvent*event){
    switch(event->key()){
    case Qt::Key_Up:
        if(direction!=2)
            direction=0;
        break;
    case Qt::Key_Right:
        if(direction!=3)
            direction=1;
        break;
    case Qt::Key_Down:
        if(direction!=0)
            direction=2;
        break;
    case Qt::Key_Left:
        if(direction!=1)
            direction=3;
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::updateGame(){
    if(!gameOver){
        moveSnake();
        checkCollision();
        update();
    }
}

void MainWindow::drawSnake()
{
    QPainter painter(this);
    QBrush brush(Qt::green);
    painter.setBrush(brush);
    for(const QPoint &point:snake){
        painter.drawRect(point.x(),point.y(),20,20);
    }
}

void MainWindow::drawFood()
{
    QPainter painter(this);
    QBrush brush(Qt::red);
    painter.setBrush(brush);
    painter.drawEllipse(food.x(),food.y(),20,20);
}

void MainWindow::moveSnake(){
    QPoint head=snake.first();
    switch(direction){
    case 0:
        head.ry()-=20;
        break;
    case 1:
        head.rx()+=20;
        break;
    case 2:
        head.ry()+=20;
        break;
    case 3:
        head.rx()-=20;
        break;
    }
    snake.prepend(head);
    if(head!=food){
        snake.removeLast();
    }else{
        spawnFood();
    }
}

void MainWindow::checkCollision(){
    QPoint head=snake.first();
    if(head.x()<0 ||head.x()>=width()||head.y()<0||head.y()>=height()){
        gameOver=true;
        return;
    }
    for(int i=1;i<snake.size();++i){
        if(head==snake.at(i)){
            gameOver=true;
            return;
        }
    }
}


void MainWindow::spawnFood(){
    int x=QRandomGenerator::global()->bounded(0,width()/20)*20;
    int y=QRandomGenerator::global()->bounded(0,height()/20)*20;
    food=QPoint(x,y);
    for(const QPoint &point:snake){
        if(food==point){
            spawnFood();
            return;
        }
    }
}
