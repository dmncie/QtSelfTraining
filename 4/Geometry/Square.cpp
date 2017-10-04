#include "Square.hpp"

Square::Square(double a) :
    a{a}
{}

double Square::getArea() {
    return a*a;
}

void Square::setArg1(double arg) {
    a = arg;
    emit areaChanged(getArea());
}

void Square::setArg2(double arg) {
    setArg1(arg);
}
