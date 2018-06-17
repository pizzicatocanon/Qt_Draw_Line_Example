#include "qmygraphicsview.h"

QmyGraphicsView::QmyGraphicsView(QWidget *parent):QGraphicsView(parent)
{

}

void QmyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    emit mygraphicsview_mousepress(event);
    QGraphicsView::mousePressEvent(event);
}

void QmyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    emit mygraphicsview_mousemove(event);
    QGraphicsView::mouseMoveEvent(event);
}
