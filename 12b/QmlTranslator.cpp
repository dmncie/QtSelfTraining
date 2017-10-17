#include "QmlTranslator.hpp"
#include <QCoreApplication>
#include <QDebug>

QmlTranslator::QmlTranslator(QObject *parent) :
    QObject(parent)
{
    setLanugage(QLocale::system().name());
}

void QmlTranslator::setLanugage(QString language) {
    qApp->removeTranslator(&m_translator);
    m_translator.load("12_" + language, ":/translations/");
    qApp->installTranslator(&m_translator);
    emit languageChanged();
}

