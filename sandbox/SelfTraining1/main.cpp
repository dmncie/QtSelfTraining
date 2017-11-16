#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    using namespace SelfTraining;

    MyClass* instance = new MyClass{};
    QObject* object = instance;

    QObject::connect(instance, &MyClass::priorityChanged,
                     [=](MyClass::Priority p){
                            std::cout << static_cast<int>(p) << std::endl;
                        });

    instance->setPriority(SelfTraining::MyClass::Critical);
    object->setProperty("priority","High");

    return a.exec();
}
