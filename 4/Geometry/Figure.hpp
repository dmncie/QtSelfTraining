#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <QObject>

class Figure : public QObject
{
    Q_OBJECT
public:
    explicit Figure(QObject *parent = nullptr);
    virtual double getArea() = 0;
    virtual ~Figure() = 0;

signals:
    void areaChanged(double);
public slots:
    virtual void setArg1(double) = 0;
    virtual void setArg2(double) = 0;
};

#endif // FIGURE_HPP
