#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsRectItem> //矩形
#include<QGraphicsEllipseItem> //椭圆
#include<QGraphicsPolygonItem> //多边形
#include<QGraphicsPixmapItem> //显示图像的元素


class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QGraphicsScene*scene;
    void createScene();


};
#endif // MAINWINDOW_H
