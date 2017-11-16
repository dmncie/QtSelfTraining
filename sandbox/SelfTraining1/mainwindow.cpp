#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMetaProperty>
#include <QString>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton(this);
    button->setText("Hello");
    QObject *object = button;

//    button->setDown(false);
    button->setGeometry(50,50,80,30);
    object->setProperty("down", true);
//    object->setProperty("flat", true);


    if (object->property("down").toBool()) {
         button->setText("Not hello");
    } else {
         button->setText("Hello2");
    }

    const QMetaObject *metaobject = object->metaObject();
    int count = metaobject->propertyCount();
    for (int i=0; i<count; ++i) {
        QMetaProperty mp = metaobject->property(i);
        const char *name = mp.name();
        QVariant value = object->property(name);
        qDebug() << i << "\t" << name << "\t" << value;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked) {
    QPushButton* ui_pushButton = findChild<QPushButton*>("pushButton");
    if (ui_pushButton->text() == "Hello") {
         ui_pushButton->setText("Bye bye");
    } else {
         ui_pushButton->setText("Hello");
    }
}
