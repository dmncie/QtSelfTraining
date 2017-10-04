#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QCheckBox>
#include <QTextBlock>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layout = new SortedLayout;
    layout->addWidget(new QPushButton(tr("Short")));
    layout->addWidget(new QPushButton(tr("Longer")));
    layout->addWidget(new QPushButton(tr("Very Long text: lorem ipsum etc itd etc")));
    layout->addWidget(new QPushButton(tr("Different text")));
    layout->addWidget(new QPushButton(tr("More text")));
    layout->addWidget(new QPushButton(tr("Even longer button text")));
    auto temp = new QTextEdit(tr("Even longer button text"));
    temp->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    layout->addWidget(temp);

    ui->verticalLayout->addLayout(layout);

    layout->setPredicate(SortedLayout::Predicate::Width);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index) {
    if (index == 0) {
        layout->setPredicate(SortedLayout::Predicate::Width);
    } else {
        layout->setPredicate(SortedLayout::Predicate::Height);
    }
    ui->verticalLayout->update();
}
