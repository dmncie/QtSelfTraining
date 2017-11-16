#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <iostream>

class Receiver: public QObject
{
    Q_OBJECT
public:
    Receiver(QObject* parent = 0 ) :
        QObject(parent)
    {}
public slots:
   void bar1() {
       std::cout << "Receiver's bar slot called\n";
   }  /* This is a public slot*/
protected slots:
   void bar2() { }  /* This is a protected slot*/
private slots:
   void bar3() { }  /* This is private slot */
};

#endif // RECEIVER_H
