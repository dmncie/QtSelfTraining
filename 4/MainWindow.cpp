#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "Geometry/Square.hpp"
#include "Geometry/Circle.hpp"
#include "Geometry/Triangle.hpp"
#include "Geometry/Rectangle.hpp"
#include <QDoubleSpinBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createFigure(0); // Square
    ui->doubleSpinBox_3->setEnabled(false);
    connectControls();
}

void MainWindow::disconnectControls() {
    figure->disconnect();
    ui->doubleSpinBox->disconnect();
    ui->doubleSpinBox->disconnect();
}

void MainWindow::connectControls() {
    ui->label_6->setText(QString::number(figure->getArea()));

    connect(figure.get(), &Figure::areaChanged,
            [=](double p) {
        ui->label_6->setText(QString::number(p));
    });

    using overload = void(QDoubleSpinBox::*)(double);
    auto valueChanged = static_cast<overload>(&QDoubleSpinBox::valueChanged);
    connect(ui->doubleSpinBox, valueChanged,
            figure.get(), &Figure::setArg1);
    connect(ui->doubleSpinBox_3, valueChanged,
            figure.get(), &Figure::setArg2);
}

void MainWindow::createFigure(int index) {
    switch (index) {
    case 0:
        figure = std::make_unique<Square>(ui->doubleSpinBox->value());
        break;
    case 1:
        figure = std::make_unique<Circle>(ui->doubleSpinBox->value());
        break;
    case 2:
        figure = std::make_unique<Triangle>(ui->doubleSpinBox->value(),
                                            ui->doubleSpinBox_3->value());
        break;
    case 3:
        figure = std::make_unique<Rectangle>(ui->doubleSpinBox->value(),
                                             ui->doubleSpinBox_3->value());
        break;
    default:
        qDebug() << tr("Unknown shape");
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index) {
    if(index <= 1) {
        ui->doubleSpinBox_3->setDisabled(true);
    } else {
        ui->doubleSpinBox_3->setDisabled(false);
    }

    disconnectControls();
    createFigure(index);
    connectControls();
}
