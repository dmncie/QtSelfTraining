#ifndef XMLTRANSLATOR_HPP
#define XMLTRANSLATOR_HPP

#include <QString>
#include <QXmlStreamReader>
#include <QJsonDocument>

class XmlTranslator {
public:
    XmlTranslator();
    QString translate(QString const& input);

private:
    QJsonDocument doc{};
    QXmlStreamReader reader;
};

#endif // XMLTRANSLATOR_HPP
