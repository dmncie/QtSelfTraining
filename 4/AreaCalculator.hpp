#ifndef AREACALCULATOR_HPP
#define AREACALCULATOR_HPP

#include <QObject>

class AreaCalculator : public QObject
{
    Q_OBJECT
public:
    explicit AreaCalculator(QObject *parent = nullptr);

signals:

public slots:

private:
    double a;
    double h;
};

#endif // AREACALCULATOR_HPP
