#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <Geometry/Figure.hpp>

class Rectangle : public Figure
{
 Q_OBJECT
public:
    Rectangle(double a, double b);
    virtual double getArea() override;
public slots:
    virtual void setArg1(double) override;
    virtual void setArg2(double) override;
private:
    double a, b;
};

#endif // RECTANGLE_HPP
