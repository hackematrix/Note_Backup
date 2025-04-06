#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPen>
#include<QBrush>
#include<QDebug>
#include<QRadialGradient>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    view=new QGraphicsView(scene,this);
    view->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(view);
    scene->setBackgroundBrush(QBrush(QColor(173,216,230)));
    currentPlayer=true;
    for(int i=0;i<BOARD_SIZE;++i){
        for(int j=0;j<BOARD_SIZE;++j){
            board[i][j]=0;
        }
    }

    initBoard();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    QPointF pos=view->mapToScene(event->pos());
    int x=static_cast<int>(pos.x()/CELL_SIZE+0.5);
    int y=static_cast<int>(pos.y()/CELL_SIZE+0.5);
    if(x>=0&&x<BOARD_SIZE&&y>=0&&y<BOARD_SIZE&&board[x][y]==0){
        board[x][y]=currentPlayer?1:2;
        drawPiece(x,y);
        if(checkWin(x,y)){
            QString message=currentPlayer?"Black wins":"White wins";
            QMessageBox::information(this,"Game Over",message);

        }
        else{
            currentPlayer=!currentPlayer;
        }
    }

}

void MainWindow::initBoard(){
    QPen gridPen(QColor(0,100,0),2);
    for(int i=0;i<BOARD_SIZE;++i){
        scene->addLine(0,i*CELL_SIZE,(BOARD_SIZE-1)*CELL_SIZE,i*CELL_SIZE,gridPen);

    }

    for(int i=0;i<BOARD_SIZE;++i){
        scene->addLine(i*CELL_SIZE,0,i*CELL_SIZE,(BOARD_SIZE-1)*CELL_SIZE,gridPen);
    }

}

void MainWindow::drawPiece(int x,int y){
    QRadialGradient gradient(0.5,0.5,0.5);
    if(currentPlayer){
        gradient.setColorAt(0,QColor(30,30,30));
        gradient.setColorAt(1,QColor(0,0,0));
    }
    else{
        gradient.setColorAt(0,QColor(255,255,255));
        gradient.setColorAt(1,QColor(220,220,220));
    }
    //设置渐变的坐标
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    QBrush brush(gradient);
    QGraphicsEllipseItem*piece=new QGraphicsEllipseItem(x*CELL_SIZE-CELL_SIZE/4,y*CELL_SIZE-CELL_SIZE/4,CELL_SIZE/2,CELL_SIZE/2);
    piece->setBrush(brush);
    piece->setPen(Qt::NoPen);
    scene->addItem(piece);
}

bool MainWindow::checkWin(int x,int y){
    int player=board[x][y];
    int count;

    //横向
    count=1;
    for(int i=x-1;i>=0&&board[i][y]==player;--i)
        ++count;

    for(int i=x+1;i<BOARD_SIZE&&board[i][y]==player;++i)
        ++count;
    if(count>=5)
        return true;

    //纵向
    count=1;
    for(int i=y-1;i>=0&&board[x][i]==player;--i)
        ++count;
    for(int i=y+1;i<BOARD_SIZE&&board[x][i]==player;++i)
        ++count;
    if(count>=5)
        return true;

    //对角线
    //正
    count=1;
    for(int i=x-1,j=y-1;i>=0&&j>=0&&board[i][j]==player;--i,--j)
        ++count;
    for(int i=x+1,j=y+1;i<BOARD_SIZE&&j<BOARD_SIZE&&board[i][j]==player;++i,++j)

        ++count;
    if(count>=5)
        return true;

    //反
    count=1;
    for(int i=x-1,j=y+1;i>=0&&j<BOARD_SIZE&&board[i][j]==player;--i,++j)
        ++count;
    for(int i=x+1,j=y-1;i<BOARD_SIZE&&j>=0&&board[i][j]==player;++i,--j)
        ++count;
    if(count>=5)
        return true;

    return false;
}
