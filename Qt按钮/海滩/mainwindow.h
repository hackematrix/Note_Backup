#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsPathItem>
#include<QGraphicsEllipseItem>
#include<QGraphicsPolygonItem>
#include<QMouseEvent> //鼠标事件
#include<QEnterEvent> //进入事件

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event)override; //鼠标按下时操作
    void onMoveSunTriggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsEllipseItem *sunItem;
    QList<QGraphicsEllipseItem*>cloudItems;//椭圆圆形项
    QGraphicsPolygonItem * palmTreeItem;

};
#endif // MAINWINDOW_H
