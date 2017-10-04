#include "Rectangle.hpp"

Rectangle::Rectangle(double a, double b) :
    a{a},
    b{b}
{}

double Rectangle::getArea() {
    return a*b;
}

void Rectangle::setArg1(double arg) {
    a = arg;
    emit areaChanged(getArea());
}

void Rectangle::setArg2(double arg) {
    b = arg;
    emit areaChanged(getArea());
}
