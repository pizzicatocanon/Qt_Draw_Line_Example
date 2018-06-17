#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setGeometry(200,200,500,500);
    QRect rect(-250,-250,500,500);
    lay = new QHBoxLayout;
    scene = new QGraphicsScene;
    view = new QGraphicsView;
    myview = new QmyGraphicsView;
    item = new QGraphicsRectItem;

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::black);

    item->setRect(rect);
    item->setPen(pen);
    scene->addItem(item);
    scene->setSceneRect(rect);
    myview->setScene(scene);
    myview->setMouseTracking(true);        //重要，设置View可已追踪鼠标位置
    myview->setRenderHint(QPainter::Antialiasing,true);
    lay->addWidget(myview);
    setLayout(lay);

    connect(myview,SIGNAL(mygraphicsview_mousepress(QMouseEvent*)),this,SLOT(mouse_press(QMouseEvent*)));
    connect(myview,SIGNAL(mygraphicsview_mousemove(QMouseEvent*)),this,SLOT(mouse_move(QMouseEvent*)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouse_press(QMouseEvent *event)
{

    if(event->button() == Qt::LeftButton)
    {
        if(mouse_down == 0)  //在鼠标首次按下时创造对象
        {
            line = new QGraphicsLineItem;
            scene->addItem(line);
        }
        qDebug() << "Left Button";
        mouse_down_pos = event->pos(); //并且记录第一次点击位置
    }
    draw_line(myview,scene,event);//调用画线函数
}

void Widget::mouse_move(QMouseEvent *event)
{
    draw_line(myview,scene,event);//调用画线函数
}

void Widget::draw_line(QmyGraphicsView const *v, QGraphicsScene *s, QMouseEvent const *event)
{
    //实现被鼠标press 和 move 事件同时调用此函数，简约代码空间

    if(event->button() == Qt::LeftButton)
    {
        mouse_down += 1;
        qDebug () << mouse_down;
    }
    if(mouse_down == 1)
    {
        QPointF line_start;
        QPointF line_end;
        line_start = v->mapToScene(mouse_down_pos);//转换view坐标到scene坐标
        line_end = v->mapToScene(event->pos());//转换view坐标到scene坐标
        line->setLine(line_start.x(),line_start.y(),line_end.x(),line_end.y());
        line->update();//更新线
    }
    else if(mouse_down ==2)
    {
        mouse_down = 0;
        line = new QGraphicsLineItem;//画完线以后，重新创造一个对象给下次循环使用
        s->addItem(line);
    }

}
