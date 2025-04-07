#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include<QPainter>
#include<QMouseEvent>
#include<QVector>

//自定义画布类,继承QWidget
class CanvasWidget:public QWidget{
    Q_OBJECT
public:
    CanvasWidget(QWidget *parent=nullptr);
protected:
    void paintEvent(QPaintEvent*event)override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
private:
    QVector<QPoint>points;
    int selectedPointIndex=-1;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    CanvasWidget *canvas;
};
#endif // MAINWINDOW_H
