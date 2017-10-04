#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <Geometry/Figure.hpp>

class Square : public Figure
{
 Q_OBJECT
public:
    Square(double a);
    virtual double getArea() override;
public slots:
    virtual void setArg1(double) override;
    virtual void setArg2(double) override;
private:
    double a;
};

#endif // SQUARE_HPP
