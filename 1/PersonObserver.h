#ifndef PERSONOBSERVER_H
#define PERSONOBSERVER_H

#include <QObject>
#include <PersonList.h>
#include <Person.h>

class PersonObserver : public QObject
{
    Q_OBJECT
public:
    PersonObserver(PersonList const& list);
private slots:
    void personAdded(Person person, size_t listSize);
    void personModified(Person person, size_t listSize);
    void personRemoved(Person person, size_t listSize);
};

#endif // PERSONOBSERVER_H
