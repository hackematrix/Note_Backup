#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include<QPainter>
#include<QMouseEvent>//鼠标事件
#include<QVector>

//画布类
class CanvasWidget:public QWidget{
    Q_OBJECT
public:
    CanvasWidget(QWidget *parent=nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QVector<QPoint>rectanglePoints;
    int selectedPointIndex=-1;
    QPoint lastMousePos;
    bool isHoveringOverVertex=false;
};
