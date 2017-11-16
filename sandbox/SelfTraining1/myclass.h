#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QColor>

namespace SelfTraining {

class MyClass : public QObject {
    Q_OBJECT

    Q_PROPERTY(Priority priority MEMBER m_priority READ priority WRITE setPriority NOTIFY priorityChanged)
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged)
    Q_ENUMS(Priority)

public:
    MyClass(QObject* parent = 0) {};

    enum Priority{Critical, High, Normal, Low};
    Priority priority() const {
        return m_priority;
    }
public slots:
    void setPriority(Priority p) {
        m_priority = p;
        emit priorityChanged(p);
    }

signals:
    void priorityChanged(Priority);
    void colorChanged(QColor);

private:
    Priority m_priority;
    QColor m_color;
};
}

#endif // MYCLASS_H
