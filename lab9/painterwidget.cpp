#include "painterwidget.h"
#include "utility"
#include <QMenu>

PainterWidget::PainterWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(1);
}

void PainterWidget::AddFigure(figure* fg)
{
    data_fg.push_back(std::unique_ptr<figure>(fg));
    update();
}

void PainterWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (const auto& i : data_fg) {
        if (i->getFlag()) {
            painter.setPen(Qt::darkBlue);
            painter.setBrush(Qt::blue);
        }
        else
        {
            painter.setPen(Qt::black);
            painter.setBrush(Qt::NoBrush);
        }
        i->draw(painter);

        if(i->getFlag()){
            QRect a(klick+QPoint{20,0},QSize(200,200));
            painter.setPen(Qt::black);
            painter.drawText(a,Qt::TextWordWrap,i->print().c_str());
        }
    }
    update();
}

void PainterWidget::mouseMoveEvent(QMouseEvent* event) {
    QPoint point(event->pos());
    for (const auto& i: data_fg)
    {
        if (i->mouseFlag(point))
        {
            update();
            klick=event->pos();
        }
            update();
    }
}

void PainterWidget::mouseReleaseEvent(QMouseEvent *event)
{
    for (const auto& i: data_fg)
    {
        if (i->press_move_dx != nullptr)
        {
            i->move_figure(event->pos() - *i->press_move_dx);
            delete i->press_move_dx;
            i->press_move_dx = nullptr;
        }
    }
    mouseMoveEvent(event);
    update();
}


void PainterWidget::mousePressEvent(QMouseEvent* event) {
    QPoint point(event->pos());

    if (event->buttons() == Qt::RightButton)
    {
        for (const auto& i: data_fg)
        {
            if (i->mouseFlag(point))
            {
                QMenu * menu = new QMenu(this);
                QAction* delete_figure = new QAction("&Delete figure",this);
                connect(delete_figure,&QAction::triggered,this,&PainterWidget::delete_figure);
                menu->addAction(delete_figure);
                menu->exec(QCursor::pos());
            }
        }
    }
    if (event->buttons() == Qt::LeftButton)
    {
        for (const auto& i: data_fg)
        {
            if (i->mouseFlag(point))
            {
                if (i->press_move_dx == nullptr)
                    i->press_move_dx = new QPoint(event->pos());
            }
        }
    }
    update();
}

void PainterWidget::delete_figure()
{
    for (auto i=data_fg.begin();i!=data_fg.end();++i)
    {
        if (i->get()->getFlag())
        {
            data_fg.remove(*i);
        }
    }
}

PainterWidget::~PainterWidget()
{
}
