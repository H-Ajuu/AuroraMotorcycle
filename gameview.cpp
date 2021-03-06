#include "gameview.h"
#include "ui_gameview.h"

GameView::GameView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    x1=200;
    y1=350;
    x2=600;
    y2=350;
    dir1=2;
    dir2=0;
    block[20][35]=true;
    block[60][35]=true;
    fTimer=new QTimer(this);
    fTimer->stop();
    fTimer->setInterval (200) ;//设置定时周期，单位：毫秒
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
    fTimer->start();
}

GameView::~GameView()
{
    fTimer->stop();
    delete fTimer;
    delete ui;
}

void GameView::paintEvent(QPaintEvent *event){
    QPainter painter1(this);
    QPainter painter2(this);
    painter1.fillRect(x1,y1,10,10,QBrush(QColor(255,0,0)));
    painter2.fillRect(x2,y2,10,10,QBrush(QColor(0,0,255)));
}

void GameView::on_timer_timeout(){
    switch(dir1){
    case 0:x1-=10;break;
    case 1:y1-=10;break;
    case 2:x1+=10;break;
    case 3:y1+=10;break;
    }
    switch(dir2){
    case 0:x2-=10;break;
    case 1:y2-=10;break;
    case 2:x2+=10;break;
    case 3:y2+=10;break;
    }
    int finish=0;
    if(x1<0||x1>=800||y1<0||y1>=700||block[x1/10][y1/10]==true){
        fTimer->stop();
        finish+=1;
    }
    if(x2<0||x2>=800||y2<0||y2>=700||block[x2/10][y2/10]==true){
        fTimer->stop();
        finish+=2;
    }
    switch (finish) {
    case 0:block[x1/10][y1/10]=true;
        block[x2/10][y2/10]=true;
        update(x1,y1,10,10);
        update(x2,y2,10,10);
        break;
    case 1:QMessageBox::information(this, "游戏结束", "2P Win!",QMessageBox::Ok,QMessageBox::NoButton);
        exit(0);
        break;
    case 2:QMessageBox::information(this, "游戏结束", "1P Win!",QMessageBox::Ok,QMessageBox::NoButton);
        exit(0);
        break;
    case 3:QMessageBox::information(this, "游戏结束", "平局",QMessageBox::Ok,QMessageBox::NoButton);
        exit(0);
        break;
    }
}

void GameView::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_A:dir1=dir1==2?2:0;break;
    case Qt::Key_W:dir1=dir1==3?3:1;break;
    case Qt::Key_D:dir1=dir1==0?0:2;break;
    case Qt::Key_S:dir1=dir1==1?1:3;break;
    case Qt::Key_Left:dir2=dir2==2?2:0;break;
    case Qt::Key_Up:dir2=dir2==3?3:1;break;
    case Qt::Key_Right:dir2=dir2==0?0:2;break;
    case Qt::Key_Down:dir2=dir2==1?1:3;break;
    }
}
