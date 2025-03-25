#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QProgressBar>
#include<QPushButton>
#include<QVBoxLayout>
#include<QWidget>
#include<QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onStartButtonClicked();
    void  onTimerTimeout();
private:
    QProgressBar* progressBar;
    QPushButton* startButton;
    QTimer *timer;
    int currentValue;

};
#endif // MAINWINDOW_H
