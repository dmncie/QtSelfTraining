#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "JsonTranslator.hpp"
#include <XmlTranslator.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    JsonTranslator jsonTranslator;
    XmlTranslator xmlTranslator;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
