#include "Message.hpp"

void Message::setAuthor(const QString &a) {
    if (a != m_author) {
        m_author = a;
        emit authorChanged();
    }
}

QString Message::author() const {
    return m_author;
}

void Message::setCreationDate(const QDateTime &a) {
    if (a != m_creationDate) {
        m_creationDate = a;
        emit creationDateChanged();
    }
}

QDateTime Message::creationDate() const {
    return m_creationDate;
}
