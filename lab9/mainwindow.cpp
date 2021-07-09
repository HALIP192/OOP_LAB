#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "circle.h"
#include "multiangle.h"
#include "rectangle.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    ui->widget->AddFigure(new circle(QPointF{300, 300},50));
    ui->widget->AddFigure(new rectangle(100,100,200,200));
    ui->widget->AddFigure(new multiangle({QPointF{400, 100},QPointF{500,200},QPointF{600,50}}));
    ui->widget->AddFigure(new multiangle({QPointF{400, 300},QPointF{500,400},QPointF{600,350},QPointF{550,250},QPointF{450,250},QPointF{420,200}}));
}
