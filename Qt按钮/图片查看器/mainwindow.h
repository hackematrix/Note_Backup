#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QFileDialog> //文件选择对话框
#include<QPixmap> //处理和显示图像

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
private slots:
    void onOpenButtonClicked();



private:
    Ui::MainWindow *ui;
    QLabel* imageLabel;
    QPushButton*openButton;


};
#endif // MAINWINDOW_H
