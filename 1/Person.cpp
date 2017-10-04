#include "Person.h"

std::ostream & operator<<(std::ostream &os, Person const& p) {
    os << "{id: " << p.getId()
       << ", name: " << p.name.toStdString()
       << ", surname: " << p.surname.toStdString()
       << ", age: " << p.age << "}";
    return os;
}
