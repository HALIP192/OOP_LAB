#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <painterwidget.h>
#include <figure.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;

    void start();
};

#endif // MAINWINDOW_H
