#include "XmlTranslator.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

XmlTranslator::XmlTranslator() :
    xml{}
{}


QString XmlTranslator::translate(QString const& input) {
    xml.clear();
    xml.addData(input.toUtf8());

    QJsonObject jsonObj;

    while (!xml.isEndDocument()) {
        auto type = xml.readNext();
        switch(type) {
        case QXmlStreamReader::Invalid:
            return "ERROR";
        case QXmlStreamReader::StartElement:
            parseJsonObject(jsonObj);
            break;
        default:
            break;
        }
    }

    if (xml.hasError()) {
        return "ERROR";
    }

    QJsonDocument doc(jsonObj);
    return QString(doc.toJson());
}


void XmlTranslator::parseJsonObject(QJsonObject& obj) {
    QString name = xml.name().toString();
    QJsonObject child;
    int currentLevel = 1;

    for (auto const& a : xml.attributes()) {
        child[a.name().toString()] = a.value().toString();
    }

    while (!xml.isEndDocument() && currentLevel > 0) {
        auto type = xml.readNext();
        switch(type) {
        case QXmlStreamReader::Invalid:
            return;
        case QXmlStreamReader::StartElement:
            parseJsonObject(child);
            break;
        case QXmlStreamReader::Characters:
            if (!xml.isWhitespace()) {
                if (child.isEmpty()) {
                    obj[name] = xml.text().toString();
                } else {
                    child["value"] = xml.text().toString();
                }
            }
            break;
        case QXmlStreamReader::EndElement:
            if (!child.isEmpty()){
                if (obj.contains(name)) {
                    if (obj[name].isArray()) {
                        QJsonArray arr = obj[name].toArray();
                        arr.push_back(child);
                        obj[name] = arr;
                    } else {
                        QJsonArray arr;
                        arr.push_back(obj[name]);
                        arr.push_back(child);
                        obj[name] = arr;
                    }
                } else {
                    obj[name] = child;
                }
            }
            --currentLevel;
            break;
        default:
            break;
        }
    }
}
