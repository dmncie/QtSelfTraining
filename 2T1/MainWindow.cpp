#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QStringList>
#include <QStandardItemModel>
#include <QMetaProperty>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTableView* obj = findChild<QTableView*>("tableView");
    QMetaObject const*  m_obj = obj->metaObject();

    QStandardItemModel* model = new QStandardItemModel(m_obj->propertyCount(), 2, this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("value")));

    obj->setModel(model);


    for (int i = 0; i < m_obj->propertyCount(); ++i) {

        model->setItem(i,0, new QStandardItem{m_obj->property(i).name()});
        model->setItem(i,1, new QStandardItem{m_obj->property(i).read(obj).toString()});
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
