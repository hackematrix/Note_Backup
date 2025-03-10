#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSpinBox>
#include<QDoubleSpinBox>
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
           void onSpinBoxValueChanged(int value);
    void onDoubleSpinBoxValueChanged(double value);


private:
    QSpinBox*spinBox;
    QDoubleSpinBox*doubleSpinBox;
    QLabel*spinLabel;
    QLabel*doubleSpinLabel;
    QWidget*centralWidget;
    QVBoxLayout*layout;



};
#endif // MAINWINDOW_H
