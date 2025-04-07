#include "mainwindow.h"
#include<QLinearGradient>

//画布类构造函数的实现
CanvasWidget::CanvasWidget(QWidget *parent):QWidget(parent)
{
    points<<QPoint(50,50)<<QPoint(200,200);
    setMouseTracking(true);
    setStyleSheet("background-color:#e6f7ff;");

}

//画布类事件处理函数
void CanvasWidget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QLinearGradient gradient(0,0,width(),height());
    gradient.setColorAt(0,QColor(230,247,255));
    gradient.setColorAt(1,QColor(210,235,255));
    painter.fillRect(rect(),gradient);

    QPen linePen(QColor(75,175,240),3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(linePen);

    if(points.size()>=2){
        painter.drawLine(points[0],points[1]);
    }

    QBrush pointBrush(QColor(255,153,153));
    painter.setBrush(pointBrush);
    for(const auto&point:points){
        painter.drawEllipse(point,7,7);
    }

}

//鼠标按下处理函数
void CanvasWidget::mousePressEvent(QMouseEvent*event){
    for(int i=0;i<points.size();++i){
        if((event->pos()-points[i]).manhattanLength()<15){
            selectedPointIndex=i;
            break;
        }
    }
}

//鼠标移动事件处理函数
void CanvasWidget::mouseMoveEvent(QMouseEvent *event){
    if(selectedPointIndex!=-1){
        points[selectedPointIndex]=event->pos();
        update();
    }
}

//鼠标释放事件函数
void CanvasWidget::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    selectedPointIndex=-1;
}

//主窗口类构造函数的实现
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(600,400);
    setStyleSheet("background-color:#ffffff");
    setWindowTitle("draw-line");
    canvas=new CanvasWidget(this);
    canvas->setGeometry(50,50,500,300);

}

MainWindow::~MainWindow() {
    delete canvas;
}
