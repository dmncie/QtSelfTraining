#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <Geometry/Figure.hpp>

class Circle : public Figure
{
 Q_OBJECT
public:
    Circle(double a);
    virtual double getArea() override;
public slots:
    virtual void setArg1(double) override;
    virtual void setArg2(double) override;
private:
    double r;
};

#endif // CIRCLE_HPP
