#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include "vector"
class multiangle:public figure
{
public:
    multiangle(std::vector<QPointF> digits);

    void draw(QPainter& qp)const override;
    bool mouseFlag(QPoint& point) override;
    std::string print() const override;
    void move_figure(QPoint a) override;
private:
    std::vector<QPointF> digits;
};

#endif // TRIANGLE_H
