#include "rectangle.h"

rectangle::rectangle(int x, int y, int width, int height):x(x),y(y),width(width),height(height)
{

}

void rectangle::draw(QPainter &qp) const
{
    qp.drawRect(x,y,width,height);
}

bool rectangle::mouseFlag(QPoint& point) {
    if (x <= point.x() && point.x() <= (x+width) &&
        y <= point.y() && point.y() <= (y+height))
        flag = 1;
    else
        flag = 0;
    return flag;
}

void rectangle::move_figure(QPoint a){
    x+=a.x();
    y+=a.y();
}

std::string rectangle::print() const {
    return "Rectangle:\nWidth  = " + std::to_string(width) + "\nHeight = " + std::to_string(height);
}

