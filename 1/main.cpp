#include <QCoreApplication>
#include <Person.h>
#include <PersonList.h>
#include <PersonObserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PersonList list{};
    PersonObserver observer{list};

    list.addPerson(Person{"Moby","Smith",21});
    list.addPerson(Person{"Boby","Bob",22});
    list.addPerson(Person{"Carl","Jr",23});
    list.addPerson(Person{"Samantha","White",24});

    list.removePerson(1);
    list.removePerson(1);
    list.removePerson(2);

    list.updatePerson(0, Person{"Moby","Smith",29});
    list.updatePerson(3, Person{"Samantha","Black",33});

    return a.exec();
}
