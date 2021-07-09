#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
class rectangle : public figure
{
public:
    rectangle(int x, int y, int width, int height);

    void draw(QPainter& qp)const override;
    bool mouseFlag(QPoint& point) override;
    std::string print() const override ;
    void move_figure(QPoint a) override;

private:
    int x,y,width,height;
};

#endif // RECTANGLE_H
