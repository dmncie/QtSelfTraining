#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_colorChange_clicked()
{
    switch (ui->colorComboBox->currentIndex()) {
    case 0:
        setStyleSheet("background-color: green;");
        break;
    case 1:
        setStyleSheet("background-color: red;");
        break;
    case 2:
        setStyleSheet("background-color: blue;");
        break;
    case 3:
        setStyleSheet("background-color: yellow;");
        break;
    default:
        setStyleSheet("background-color: default;");
    }
}
