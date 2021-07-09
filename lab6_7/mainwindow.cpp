#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "person.h"
#include "personcsv.h"
#include "csvreader.h"
#include <vector>
#include "jsonreader.h"
#include <QFileDialog>
#include <csvexception.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


std::vector<Person> FileType(AbstarctReader& file, Ui::MainWindow* ui) {
    try {
        if (!file.is_open()) {
            //throw CSVexception("Error, file don't open");
        }
        QString str = ui->lineEdit->text();
        if (!str.size()) {
            throw CSVexception("Void");
        }
        return file.Read();
    }  catch (std::exception& err) {
        ui->textBrowser->WriteError(QString(err.what()));
        return std::vector<Person>();
    }
}


void MainWindow::find() {
    // Дописать работу с JSON
    QString str = ui->lineEdit->text();
    std::vector<Person> mas;
    if (name_file[name_file.size() - 1] == 't' &&
        name_file[name_file.size() - 2] == 'x' &&
        name_file[name_file.size() - 3] == 't' &&
        name_file[name_file.size() - 4] == '.') {
        CSVReader file(name_file.toStdString());
        mas = FileType(file, ui);
    } else {
        JSONReader file(name_file.toStdString());
        mas = FileType(file, ui);
    }
    if (!mas.size())
        return;
    try
    {
        for(const auto& i : mas)
        {
           const char* bl=i.GetYear().c_str();
           int j=0;
           while (*(bl+j)!='\0')
           {
               if(*(bl+j)-'0'>9 || *(bl+j)<0)
                   throw CSVexception("invalid input date ");
               j++;
           }
        }


    }catch(std::exception& err)
    {
         ui->textBrowser->WriteError(QString(err.what()));
         return;
    }
    if (str == "all") {
        str = "";
        for (const auto& i : mas) {
            str += QString(i.GetFIO().c_str()) + QString(' ') + QString(i.GetYear().c_str()) + QString('\n');
        }
        ui->textBrowser->setText(str);
        return;
    }
    auto people = std::find_if(mas.begin(), mas.end(), [str](const Person& a){ return a.GetFIO() == str.toStdString(); });
    if (people == mas.end()) {
         ui->textBrowser->setText("Person is not find");
         return;
    }
    QString word = QString(people->GetFIO().c_str() + QString(' ') + QString(people->GetYear().c_str()));
    ui->textBrowser->setText(word);

    //std::string word = "qwerqwer";
    //QString new_word(word.c_str());
}

bool  check(const std::string& word) {
    for (size_t i = 0; i < word.size(); i++) {
        if (i == 2 || i == 5) {
            if (word[i] != '.')
                return 0;
        } else {
            if (!('0' <= word[i] && word[i] <= '9'))
                return 0;
        }
    }
    return 1;
}

void MainWindow::add() {
    QString str = ui->lineEdit_2->text();
    QString str2 = ui->lineEdit_3->text();
    QString str3 = ui->comboBox->currentText();
    str.chop(2);
    str2.chop(2);
    if (!check(str2.toStdString())) {
        ui->textBrowser->WriteError("Date is not correct");
        return;
    }
    ui->textBrowser->append("add : " + str + ' ' + str2 + ' ' + str3);
    PersonCsv csv("", "output.txt");
    if (!csv.out_is_open()) {
        return;
    }
    csv << Person(str.toStdString(), str2.toStdString(), str3.toStdString());
}

void MainWindow::lab4() {
    std::vector<Person*> mas;
    Boss a("a", "12.12.1212", Sex::MALE, 10);
    Student b("b", "12.12.1212", Sex::MALE, 5);
    Worker c("c", "12.12.1212", Sex::MALE, 10000);
    mas.push_back(&a);
    mas.push_back(&b);
    mas.push_back(&c);
    for (const auto& i : mas) {
        ui->textBrowser->append("new : " + QString(i->Print().c_str()));
    }
    ui->textBrowser->WriteError("Hello");
}

void MainWindow::view() {
     name_file = QFileDialog::getOpenFileName(this, tr("Open Text"), "/home/code/QT", tr("Text Files (*.txt *.csv *.json)"));
}
