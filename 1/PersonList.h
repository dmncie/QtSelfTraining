#ifndef PERSONLIST_H
#define PERSONLIST_H

#include <QObject>
#include <vector>
#include <Person.h>

class PersonList : public QObject
{
    Q_OBJECT

public:
    PersonList();
//    PersonList(const PersonList& p);
//    PersonList(PersonList&& p);
//    PersonList& operator=(PersonList p);
//    PersonList& operator=(PersonList&& p);


    void addPerson(Person p);
    void updatePerson(int id, Person p);
    void removePerson(int id);

    void printList();

signals:
    void personAdded(Person person, size_t listSize);
    void personModified(Person person, size_t listSize);
    void personRemoved(Person person, size_t listSize);

private:
    std::vector<Person> people;
    int index;
};

#endif // PERSONLIST_H
