#include "MainWindow.hpp"
#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QSpinBox>
#include <QDebug>
#include <limits>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_progress = new QProgressBar(this);
    m_label = new QLabel(this);
    m_spinbox = new QSpinBox(this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_spinbox);
    layout->addWidget(m_label);
    layout->addWidget(m_progress);

    QWidget* w = new QWidget();
    w->setLayout(layout);

    setCentralWidget(w);

    m_spinbox->setValue(0);
    m_spinbox->setMaximum(std::numeric_limits<int>::max());
    m_label->setText("0");
    m_progress->setMinimum(0);
    m_progress->setMaximum(100);

    connect(m_spinbox,
            static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this,
            &MainWindow::updateVec);
}

void MainWindow::updateProgress(int progress) {
    qDebug() << "progress: " << progress;
    m_progress->setValue(progress);
}

void MainWindow::updateResult(int result){
     m_label->setText(QString::number(result));
}


void MainWindow::intializeVec(int n) {
    m_spinbox->setValue(n);
}

void MainWindow::generateVec(int n) {
    m_progress->setValue(0);
    vec.resize(static_cast<unsigned int>(n));
    std::iota(begin(vec), end(vec),0);
    emit dataVectorChanged(vec);
}

std::vector<int>& MainWindow::getVec() {
    return vec;
}

void MainWindow::updateVec(int n) {
    generateVec(n);
}
