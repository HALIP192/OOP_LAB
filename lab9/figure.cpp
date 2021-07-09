#include "figure.h"



figure::figure() : press_move_dx(nullptr)
{

}

bool figure::getFlag() const {
    return flag;
}

void figure::draw(QPainter &qp) const
{
    qp.drawLine(0,0,100,100);
}

figure::~figure()
{

}
