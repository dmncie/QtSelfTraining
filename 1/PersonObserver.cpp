#include "PersonObserver.h"
#include <iostream>

PersonObserver::PersonObserver(PersonList const& list) {
    connect(&list, &PersonList::personAdded, this, &PersonObserver::personAdded);
    connect(&list, &PersonList::personModified, this, &PersonObserver::personModified);
    connect(&list, &PersonList::personRemoved, this, &PersonObserver::personRemoved);
}

void PersonObserver::personAdded(Person person, size_t listSize) {
    std::cout << "Person added: " << person << " list size: " << listSize << '\n';
}

void PersonObserver::personModified(Person person, size_t listSize) {
    std::cout << "Person modified: " << person << " list size: " << listSize << '\n';

}

void PersonObserver::personRemoved(Person person, size_t listSize) {
    std::cout << "Person removed: " << person << " list size: " << listSize << '\n';
}
