#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_gameStart_clicked()
{
    GameView *gv=new GameView();
    gv->show();
}

void MainWindow::on_gameDescription_clicked()
{
    QString dlgTitle="游戏说明";
    QString strInfo="1P使用WASD控制，2P使用方向键控制，最先撞击墙壁或尾迹者判负";
    QMessageBox::information(this, dlgTitle, strInfo,QMessageBox::Ok,QMessageBox::NoButton);
}
