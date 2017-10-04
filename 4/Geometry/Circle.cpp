#include "Circle.hpp"

const double Pi = 3.14;

Circle::Circle(double r) :
    r{r}
{}

double Circle::getArea() {
    return Pi * r * r;
}

void Circle::setArg1(double arg) {
    r = arg;
    emit areaChanged(getArea());
}

void Circle::setArg2(double arg) {
    setArg1(arg);
}
