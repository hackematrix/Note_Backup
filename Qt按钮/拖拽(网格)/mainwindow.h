#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include<QPainter>
#include<QMouseEvent>
#include<QVector>
#include<QPointF>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event)override;
    void resizeEvent(QResizeEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;

private:
    QVector<QVector<QPointF>>gridPoints;
    QPointF *draggedVertex;
    bool isDraggingVertex;
    int gridSize;
    int lineWidth;
    int vertexRadius;
    void initializeGrid();
    void drawGrid(QPainter &painter);
    void drawVertex(QPainter &painter);
    QPointF *findNearestVertex(const QPointF &point);

};
#endif // MAINWINDOW_H
