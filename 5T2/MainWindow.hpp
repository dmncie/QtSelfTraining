#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "SortedLayout.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    SortedLayout* layout;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
