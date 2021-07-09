#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <iostream>
#include <memory>
#include <list>
#include <figure.h>
#include "functional"
class PainterWidget : public QWidget
{
    Q_OBJECT
private:
    std::list<std::unique_ptr<figure>> data_fg;
    QPoint klick;
public:
    explicit PainterWidget(QWidget *parent = nullptr);

    void AddFigure(figure* fg);
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void delete_figure();

    ~PainterWidget()override;

signals:

public slots:
};

#endif // PAINTERWIDGET_H
