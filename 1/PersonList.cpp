#include "PersonList.h"
#include <iostream>

PersonList::PersonList():
    index{0}
{}


void PersonList::addPerson(Person person) {
    person.setId(index++);
    people.push_back(person);
    emit personAdded(person, people.size());
}

void PersonList::updatePerson(int id, Person person) {
    auto it = find_if(begin(people), end(people), [id](Person& p){ return p.getId() == id; });
    if (it != end(people)) {
        person.setId(it->getId());
        *it = person;
        emit personModified(person, people.size());
    }
}

void PersonList::removePerson(int id) {
    auto it = find_if(begin(people), end(people), [id](Person& p){ return p.getId() == id; });
    if (it != end(people)) {
       auto person = *it;
       people.erase(remove_if(begin(people),
                              end(people),
                              [id](Person& p){ return p.getId() == id; }),
               end(people));
        emit personRemoved(person, people.size());
    }
}

void PersonList::printList() {
    for (auto& p : people) {
         std::cout << p  << '\n';
    }
}

