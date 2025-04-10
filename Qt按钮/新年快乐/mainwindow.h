#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsTextItem>
#include<QGraphicsEllipseItem>
#include<QGraphicsRectItem>
#include<QTimer>
#include<QRandomGenerator>
#include<QMouseEvent>


//烟花粒子类
class FireworksParticle:public QObject,public QGraphicsEllipseItem{
    Q_OBJECT

public:
    FireworksParticle(QPointF startPos,QColor color,QGraphicsScene *scene);
private slots:
    void updatePosition();
private:
    QGraphicsScene *m_scene;
    QTimer *m_timer;
    qreal m_vx;
    qreal m_vy;
};

//定义视图类
class CustomView:public QGraphicsView{
    Q_OBJECT
public:
    CustomView(QGraphicsScene *scene,QWidget *parent=nullptr);
protected:
    void mousePressEvent(QMouseEvent *event)override;
private:
    void createFireworks(const QPointF &pos);
    QGraphicsScene *m_scene;

};






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

private:
    Ui::MainWindow *ui;
    QGraphicsScene * m_scene;
    CustomView *m_view;
};
#endif // MAINWINDOW_H
