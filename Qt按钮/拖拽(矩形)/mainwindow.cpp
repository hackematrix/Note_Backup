#include "mainwindow.h"
#include<QLinearGradient>

//画布类构造函数的实现
CanvasWidget::CanvasWidget(QWidget *parent):QWidget(parent){
    rectanglePoints<<QPoint(100,100)<<QPoint(300,100)<<QPoint(300,300)<<QPoint(100,300);
    setMouseTracking(true);
    setStyleSheet("background-color:#E0F7FA;");

}

//画布类绘制类处理函数的实现
void CanvasWidget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QLinearGradient gradient(0,0,width(),height());
    gradient.setColorAt(0,QColor(224,247,250));
    gradient.setColorAt(1,QColor(178,235,242));
    painter.fillRect(rect(),gradient);

    painter.setBrush(QColor(255,205,210));
    painter.setPen(QPen(QColor(239,154,154),2));
    painter.drawPolygon(rectanglePoints);

    painter.setBrush(QColor(239,108,0));
    for(const auto&point:rectanglePoints){
        painter.drawEllipse(point,5,5);
    }
}

//鼠标按下操作
void CanvasWidget::mousePressEvent(QMouseEvent *event){
    for(int i=0;i<rectanglePoints.size();++i){
        QRect pointRect(rectanglePoints[i].x()-5,rectanglePoints[i].y()-5,10,10);
        if(pointRect.contains(event->pos())){
            selectedPointIndex=i;
            lastMousePos=event->pos();
            break;
        }
    }
}

//鼠标移动操作
void CanvasWidget::mouseMoveEvent(QMouseEvent *event){
    bool foundHoverVertex=false;
    for(int i=0;i<rectanglePoints.size();++i){
        QRect pointRect(rectanglePoints[i].x()-5,rectanglePoints[i].y()-5,10,10);
        if(pointRect.contains(event->pos())){
            if(!foundHoverVertex){
                setCursor(Qt::PointingHandCursor);
                isHoveringOverVertex=true;
            }
            foundHoverVertex=true;
            break;
        }
    }

    if(!foundHoverVertex&&isHoveringOverVertex){
        setCursor(Qt::ArrowCursor);
        isHoveringOverVertex=false;
    }

    if(selectedPointIndex!=-1){
        QPoint offset=event->pos()-lastMousePos;
        rectanglePoints[selectedPointIndex]+=offset;
        lastMousePos=event->pos();
        update();
    }

}


void CanvasWidget::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    selectedPointIndex=-1;
    setCursor(Qt::ArrowCursor);
    isHoveringOverVertex=false;

}

 MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(600,400);
    setWindowTitle("rect_drag");
    canvas=new CanvasWidget(this);
    canvas->setGeometry(0,0,600,400);

}

MainWindow::~MainWindow() {
    delete canvas;
}
