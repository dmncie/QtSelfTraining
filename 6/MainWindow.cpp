#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    jsonTranslator{},
    xmlTranslator{}
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    if(ui->comboBox->currentIndex() == 0) {
        ui->outputText->setPlainText(
                    jsonTranslator.translate(ui->inputText->toPlainText())
                    );
    } else {
        ui->outputText->setPlainText(
                    xmlTranslator.translate(ui->inputText->toPlainText())
                    );
    }
}
