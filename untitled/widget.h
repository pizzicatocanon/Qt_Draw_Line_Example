#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qmygraphicsview.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QHBoxLayout>
#include <QRect>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsLineItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void mouse_press(QMouseEvent *event);
    void mouse_move(QMouseEvent *event);
private:
    QHBoxLayout *lay;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QmyGraphicsView *myview;
    QGraphicsRectItem *item;
    QGraphicsLineItem *line;



    Ui::Widget *ui;
    void draw_line(QmyGraphicsView const *v, QGraphicsScene *s, QMouseEvent const *event);
    int mouse_down = 0;//鼠标点击次数记录
    QPoint mouse_down_pos;//每次点击鼠标的坐标
};

#endif // WIDGET_H
