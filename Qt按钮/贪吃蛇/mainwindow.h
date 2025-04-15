#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QKeyEvent>
#include<QVector>
#include<QPoint>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent*event)override;
    void keyPressEvent(QKeyEvent *event)override;


private slots:
    void updateGame();
private:
    void drawSnake();
    void drawFood();
    void spawnFood();
    void moveSnake();
    void checkCollision();
    QVector<QPoint>snake;
    QPoint food;
    QTimer *timer;
    int direction;
    bool gameOver;
};
#endif // MAINWINDOW_H
