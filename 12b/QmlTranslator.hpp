#ifndef QMLTRANSLATOR_HPP
#define QMLTRANSLATOR_HPP

#include <QObject>
#include <QTranslator>

class QmlTranslator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)

public:
    explicit QmlTranslator(QObject *parent = 0);

    // A hack, 'emptyString' should be concatenaded with every string in QML.
    // when language is changed, a notification will be sent,
    // stating that 'emptyString' changed, therefore QML will be
    // tricked to reaload all its strings
    QString getEmptyString() {
        return "";
    }
signals:
    void languageChanged();

public:
    Q_INVOKABLE void setLanugage(QString language);

private:
    QTranslator m_translator;
};


#endif // QMLTRANSLATOR_HPP
