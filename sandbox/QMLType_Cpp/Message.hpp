#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QObject>
#include <QString>
#include <QDateTime>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate NOTIFY creationDateChanged)

public:
    void setAuthor(const QString &a);
    QString author() const;
    void setCreationDate(const QDateTime &a);
    QDateTime creationDate() const;

signals:
    void authorChanged();
    void creationDateChanged();

private:
    QString m_author;
    QDateTime m_creationDate;
};

#endif // MESSAGE_HPP
