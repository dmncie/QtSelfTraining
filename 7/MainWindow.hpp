#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <vector>

class QProgressBar;
class QLabel;
class QSpinBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void intializeVec(int n);
    std::vector<int>& getVec();

public slots:
    void updateProgress(int);
    void updateResult(int);

signals:
    void dataVectorChanged(std::vector<int>&);

private slots:
    void updateVec(int);

private:
    void generateVec(int n);

private:
    std::vector<int> vec;
    QProgressBar* m_progress;
    QLabel* m_label;
    QSpinBox* m_spinbox;
};

#endif // MAINWINDOW_HPP
