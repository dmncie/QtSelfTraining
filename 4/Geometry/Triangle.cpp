#include "Triangle.hpp"

Triangle::Triangle(double a, double h) :
    a{a},
    h{h}
{}

double Triangle::getArea() {
    return a * h / 2;
}

void Triangle::setArg1(double arg) {
    a = arg;
    emit areaChanged(getArea());
}

void Triangle::setArg2(double arg) {
    h = arg;
    emit areaChanged(getArea());
}
