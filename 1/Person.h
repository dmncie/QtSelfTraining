#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <ostream>

class Person
{
public:
    explicit Person(QString name, QString surname, int age) :
        name{name},
        surname{surname},
        age{age},
        id{}
    {}

    Person(Person const& o) = default;
    Person(Person && o) = default;
    Person& operator=(Person& o) = default;
    Person& operator=(Person&& o) = default;

    void setId(int new_id) {
        id = new_id;
    }

    int getId() const {
        return id;
    }

private:
    friend std::ostream& operator<<(std::ostream &os, const Person& p);

    QString name;
    QString surname;
    int age;
    int id;
};

#endif // PERSON_H
