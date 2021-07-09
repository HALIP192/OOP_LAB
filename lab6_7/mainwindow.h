#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "errortextbrowser.h"
#include "person.h"
#include "personcsv.h"
#include "boss.h"
#include "worker.h"
#include "student.h"
#include <vector>
#include <algorithm>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void add();
    void find();
    void lab4();
    void view();

private:
    Ui::MainWindow *ui;
    QString name_file;
};



#endif // MAINWINDOW_H
