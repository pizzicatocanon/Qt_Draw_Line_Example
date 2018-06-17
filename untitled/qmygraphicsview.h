#ifndef QMYGRAPHICSVIEW_H
#define QMYGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>



class QmyGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    QmyGraphicsView(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
signals:
    void mygraphicsview_mousepress(QMouseEvent *event);
    void mygraphicsview_mousemove(QMouseEvent *event);


};

#endif // QMYGRAPHICSVIEW_H
