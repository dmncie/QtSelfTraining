#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QObject>
#include <QDebug>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)

public:
    // Doesn't have to be Q_INVOKABLE, Q_PROPERTY handles everything
    void setAuthor(const QString &a) {
        if (a != m_author) {
            m_author = a;
            emit authorChanged();
        }
    }

    Q_INVOKABLE bool isOld(int age) const {
        qDebug() << "isOld C++ method called with age:" << age;
        return age > 100;
    }

    QString author() const {
        return m_author;
    }

public slots:
    void response(QString msg) {
        qDebug() << "response slot called with msg: " << msg;
    }

signals:
    void authorChanged();

private:
    QString m_author;
};

#endif // MESSAGE_HPP
