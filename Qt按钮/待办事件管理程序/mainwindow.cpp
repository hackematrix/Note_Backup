#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVBoxLayout>
#include<QPalette>
#include<QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建输入框

    inputLineEdit=new QLineEdit(this);
    inputLineEdit->setFixedHeight(35);
    inputLineEdit->setStyleSheet("padding:8px;border:1px solid #ccc;border-radius:6px;background-color:white");

    //添加按钮
    addButton=new QPushButton("添加",this);
    addButton->setFixedHeight(35);
    addButton->setStyleSheet("background-color:#007BFF;color:white;padding:8px 16px;border:none;border-radius:6px");
    addButton->setCursor(Qt::PointingHandCursor);

    //创建待办事项列表
    todoListWidget=new QListWidget(this);
    todoListWidget->setStyleSheet("background-color:white;border:1px solid #ccc;border-radius:6px");

    //删除按钮
    deleteButton=new QPushButton("删除",this);
    deleteButton->setFixedHeight(35);
    deleteButton->setStyleSheet("background-color:#dc3545;color:white;padding:8px 16px;border:none;border-radius:6px");
    deleteButton->setCursor(Qt::PointingHandCursor);

    //布局
    QVBoxLayout*mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(inputLineEdit);
    mainLayout->addWidget(addButton);
    mainLayout->addWidget(todoListWidget);
    mainLayout->addWidget(deleteButton);

    //设置中央部件
    QWidget*centralWidget=new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    //窗口背景
    QPalette palette=this->palette();
    palette.setColor(QPalette::Window,QColor(245,245,245));
    this->setPalette(palette);

    QFont font("Arial",12);
     this->setFont(font);

    //连接
    connect(addButton,&QPushButton::clicked,this,&MainWindow::onAddButtonClicked);
    connect(deleteButton,&QPushButton::clicked,this,&MainWindow::onDeleteButtonClicked);
    connect(todoListWidget,&QListWidget::itemClicked,this,&MainWindow::onItemClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddButtonClicked(){
    QString todoText=inputLineEdit->text().trimmed();
    if(!todoText.isEmpty()){
        QListWidgetItem*item=new QListWidgetItem(todoText);
        item->setFlags(item->flags()|Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        todoListWidget->addItem(item);
        inputLineEdit->clear();
    }
}

void MainWindow::onDeleteButtonClicked(){
    QList<QListWidgetItem*>selectedItems=todoListWidget->selectedItems();
    foreach(QListWidgetItem*item,selectedItems){
        delete todoListWidget->takeItem(todoListWidget->row(item));
    }
}

void MainWindow::onItemClicked(QListWidgetItem*item){
    if(item->checkState()==Qt::Checked){
        item->setCheckState(Qt::Unchecked);
        item->setForeground(Qt::black);
        item->setFont(QFont("Arial",12));
    }else{
        item->setCheckState(Qt::Checked);
        item->setForeground(Qt::gray);
        QFont strikeThroughFont=item->font();
        strikeThroughFont.setStrikeOut(true);
        item->setFont(strikeThroughFont);
    }
}
