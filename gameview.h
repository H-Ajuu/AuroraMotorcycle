#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QBrush>
#include <QKeyEvent>
#include <QMessageBox>
namespace Ui {
class GameView;
}

class GameView : public QWidget
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);
    ~GameView();
    void paintEvent(QPaintEvent *);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::GameView *ui;
    QTimer *fTimer;
    int x1,y1,dir1,x2,y2,dir2;
    bool block[80][70];

private slots:
    void on_timer_timeout ();
};

#endif // GAMEVIEW_H
