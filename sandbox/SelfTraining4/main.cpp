#include <QObject>
#include <counter.h>
#include <sender.h>
#include <receiver.h>
#include <iostream>
#include <QTimer>

int main() {
    Sender sender{};
    Receiver receiver{};

    QObject::connect(&sender,   &Sender::foo,
                     &receiver, &Receiver::bar1);

//    QTimer::singleShot(1000, &receiver, &Receiver::bar1);

    sender.method1();

    Counter x, y;
    QObject::connect(&x, &Counter::valueChanged,
                     &y, &Counter::setValue);

    x.setValue(12);     // a.value() == 12, b.value() == 12
    std::cout << "x:" << x.value() << "; y:" << y.value() << '\n';

    y.setValue(48);     // a.value() == 12, b.value() == 48
    std::cout << "x:" << x.value() << "; y:" << y.value() << '\n';

    return 0;
}
