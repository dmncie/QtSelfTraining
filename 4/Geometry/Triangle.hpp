#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <Geometry/Figure.hpp>

class Triangle : public Figure
{
 Q_OBJECT
public:
    Triangle(double a, double h);
    virtual double getArea() override;
public slots:
    virtual void setArg1(double) override;
    virtual void setArg2(double) override;
private:
    double a, h;
};

#endif // TRIANGLE_HPP
