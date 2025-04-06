#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsEllipseItem>
#include<QGraphicsLineItem>
#include<QMouseEvent>

const int BOARD_SIZE=15;
const int CELL_SIZE=40;

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
    void mousePressEvent(QMouseEvent *event)override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    bool currentPlayer;
    int board[BOARD_SIZE][BOARD_SIZE];
    void initBoard();
    void drawPiece(int x,int y);
    bool checkWin(int x,int y);
};
#endif // MAINWINDOW_H
