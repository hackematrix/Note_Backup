#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSlider>
#include<QLabel>
#include<QVBoxLayout>
#include<QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onSliderValueChanged(int value);

private:
    QSlider *slider;
    QLabel *valueLabel;

};
#endif // MAINWINDOW_H
