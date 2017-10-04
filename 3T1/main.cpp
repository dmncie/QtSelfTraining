#include <QCoreApplication>
#include <QList>
#include <QMap>
#include <iostream>

struct Person {
    QString name;
    QString surname;
    int age;
};

void print(Person const& p){
    std::cout << "{" << p.name.toStdString()
              << ", " << p.surname.toStdString()
              << ", " << p.age << "}\n";
}

void testQList() {
    QList<Person> list {{"A","B",1},
                        {"B","C",2},
                        {"C","D",3},
                        {"D","E",4},
                        {"E","F",5},
                        {"F","G",6},
                        {"G","H",7},
                        {"H","I",8},
                        {"I","J",9},
                        {"J","K",10},
                        {"A","B",11},
                        {"B","C",12},
                        {"C","D",13},
                        {"D","E",14},
                        {"E","F",15},
                        {"F","G",16},
                        {"G","H",17},
                        {"H","I",18},
                        {"I","J",19},
                        {"J","K",20}};

    for (int i = 0; i < list.size(); i++) {
        print(list[i]);
    }

    std::cout << '\n';

    for (auto const& p : list) {
        print(p);
    }

    std::cout << '\n';

    QListIterator<Person> it(list);
    while(it.hasNext()) {
        print(it.next());
    }

    std::cout << '\n';

    QMutableListIterator<Person> it3(list);
    while(it3.hasNext()) {
        if (it3.next().age %2 == 0) {
            it3.remove();
        }
    }

    std::cout << '\n';

    QList<Person>::const_iterator it2;
    for (it2 = list.cbegin(); it2 != list.cend(); it2++) {
        print(*it2);
    }
}

void testQMap() {
    QMap<int, Person> map {{21, {"A","B",1}},
                           {22, {"B","C",2}},
                           {23, {"C","D",3}},
                           {24, {"D","E",4}},
                           {25, {"E","F",5}},
                           {26, {"F","G",6}},
                           {27, {"G","H",7}},
                           {28, {"H","I",8}},
                           {29, {"I","J",9}},
                           {30, {"J","K",10}},
                           {31, {"A","B",11}},
                           {32, {"B","C",12}},
                           {33, {"C","D",13}},
                           {34, {"D","E",14}},
                           {35, {"E","F",15}},
                           {36, {"F","G",16}},
                           {37, {"G","H",17}},
                           {38, {"H","I",18}},
                           {39, {"I","J",19}},
                           {40, {"J","K",20}}};

    std::cout << "Range for" << '\n';

    for (auto const& p : map) {
        print(p);
    }

    for (auto const& p : map.keys()) {
        std::cout << p << "\n";
    }

    for (auto const& p : map.values()) {
        print(p);
    }


    std::cout << "Java iterator" << '\n';

    QMapIterator<int, Person> it(map);
    while(it.hasNext()) {
        std::cout << it.next().key() << ": ";
        print(it.value());
    }

    std::cout << "Java mutable iterator" << '\n';

    QMutableMapIterator<int, Person> it3(map);
    while(it3.hasNext()) {
        if (it3.next().key() %2 == 0) {
            it3.remove();
        }
    }

    std::cout << "C++ style iterator" << '\n';

    QMap<int, Person>::const_iterator it2;
    for (it2 = map.cbegin(); it2 != map.cend(); it2++) {
        print(*it2);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //testQList();
    testQMap();

    return a.exec();
}
