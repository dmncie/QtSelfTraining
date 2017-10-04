#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <Geometry/Figure.hpp>
#include <memory>

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
    void connectControls();
    void disconnectControls();
    void createFigure(int index);

    std::unique_ptr<Figure> figure;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
