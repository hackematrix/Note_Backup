#include "mainwindow.h"
#include<QPainter>
#include<QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),isDraggingVertex(false),draggedVertex(nullptr),gridSize(100),lineWidth(3),vertexRadius(8)
{
    initializeGrid();
    setFixedSize(800,600);

}

MainWindow::~MainWindow() {}

void MainWindow::initializeGrid(){
    gridPoints.clear();
    for(int x=0;x<=width();x+=gridSize){
        QVector<QPointF>column;
        for(int y=0;y<=height();y+=gridSize){
            column.append(QPointF(x,y));
        }
        gridPoints.append(column);
    }
}

void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    QLinearGradient gradient(0,0,width(),height());
    gradient.setColorAt(0,QColor(255,255,255));
    gradient.setColorAt(1,QColor(255,228,225));
    painter.fillRect(rect(),gradient);
    drawGrid(painter);
    drawVertex(painter);
}

void MainWindow::drawGrid(QPainter &painter){
    painter.setPen(QPen(QColor(100,100,100),lineWidth,Qt::SolidLine,Qt::RoundCap));
    //垂直
    for(int x=0;x<gridPoints.size();++x){
        for(int y=0;y<gridPoints[x].size()-1;++y){
            painter.drawLine(gridPoints[x][y],gridPoints[x][y+1]);
        }
    }
    //水平
    for(int y=0;y<gridPoints[0].size();++y){
        for(int x=0;x<gridPoints.size()-1;++x){
            painter.drawLine(gridPoints[x][y],gridPoints[x+1][y]);
        }
    }
}

void MainWindow::drawVertex(QPainter &painter){
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255,105,105));

    for(int x=0;x<gridPoints.size();++x){
        for(int y=0;y<gridPoints[x].size();++y){
            painter.setRenderHint(QPainter::Antialiasing);
            painter.drawEllipse(gridPoints[x][y],vertexRadius,vertexRadius);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        draggedVertex=findNearestVertex(event->pos());
        if(draggedVertex){
            isDraggingVertex=true;
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(isDraggingVertex &&draggedVertex)
    {
        draggedVertex->setX(event->pos().x());
        draggedVertex->setY(event->pos().y());
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        isDraggingVertex=false;
        draggedVertex=nullptr;
    }
}

QPointF *MainWindow::findNearestVertex(const QPointF &point)
{
    for(int x=0;x<gridPoints.size();++x){
        for(int y=0;y<gridPoints[x].size();++y){
            {
                if(QLineF(point,gridPoints[x][y]).length()<=vertexRadius){
                    return &gridPoints[x][y];
                }
            }
        }
    }
    return nullptr;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
    initializeGrid();
    update();
}
