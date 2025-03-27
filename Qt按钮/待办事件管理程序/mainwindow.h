#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLineEdit>
#include<QPushButton>
#include<QListWidget>

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
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void onItemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QLineEdit*inputLineEdit;
    QPushButton*addButton;
    QListWidget*todoListWidget;
    QPushButton*deleteButton;

};
#endif // MAINWINDOW_H
