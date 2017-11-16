#ifndef SENDER_H
#define SENDER_H
#include <QObject>

class Sender : public QObject
{
    Q_OBJECT
public:
    Sender(QObject* parent = 0 ) : QObject(parent)
    {
    }
signals: /* signals to be declared under 'signals' access specifier */
   void foo();  /* This is a signal declaration -- a pure declaration as a method.*/
public:
   void method1()
   {
        /* some lines of code executed before this line*/
         emit foo(); /* This is the firing/raising of the signal 'foo'. */
        /* some lines of code executed after this line*/
   }
};

#endif // SENDER_H
