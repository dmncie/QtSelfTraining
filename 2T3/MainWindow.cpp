#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(":/loremipsum");

    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line.append(stream.readLine()+"\n");
        }
        ui->label->setText(line);
    }
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
