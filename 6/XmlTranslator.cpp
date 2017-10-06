#include "XmlTranslator.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

XmlTranslator::XmlTranslator() :
    doc{},
    reader{}
{
}


QString XmlTranslator::translate(QString const& input) {
    reader.addData(input.toUtf8());

    while (!reader.atEnd()) {
        switch(reader.readNext()) {
        case QXmlStreamReader::NoToken:
            break;
        case QXmlStreamReader::Invalid:
            break;
        case QXmlStreamReader::StartDocument:
            break;
        case QXmlStreamReader::EndDocument:
            break;
        case QXmlStreamReader::StartElement:
            break;
        case QXmlStreamReader::EndElement:
            break;
        default:
            reader.skipCurrentElement();
        }
    }

    if (reader.hasError()) {
        return "ERROR";
    }

    return "";
}

