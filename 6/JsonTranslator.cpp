#include "JsonTranslator.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

JsonTranslator::JsonTranslator() :
    output{},
    writer{&output}
{
    writer.setAutoFormatting(true);
}


QString JsonTranslator::translate(QString const& input) {
    QJsonDocument doc(QJsonDocument::fromJson(input.toUtf8()));
    output.clear();
    // check validity of the document
    if(!doc.isNull()) {
        if(doc.isObject()) {
            writer.writeStartDocument();
            parseObject(doc.object());
            writer.writeEndDocument();
        } else {
            return "ERROR";
        }
    } else {
        return "ERROR";
    }

    return output;
}

void JsonTranslator::parseObject(QJsonObject const& obj) {
    for (auto const& s : obj.keys()) {
        parseValue(s, obj[s]);
    }
}

void JsonTranslator::parseArray(QString const& name, QJsonArray const& arr) {
    for (auto const& a : arr) {
        parseValue(name, a);
    }
}

void JsonTranslator::parseValue(QString const& name, QJsonValue const& val) {
    if (val.isObject()) {
        writer.writeStartElement(name);
        parseObject(val.toObject());
        writer.writeEndElement();
    } else if (val.isArray()) {
        parseArray(name, val.toArray());
    } else {
        switch (val.type()) {
        case QJsonValue::String:
            elementCreator(name, val.toString());
            break;
        case QJsonValue::Double:
            elementCreator(name, QString::number(val.toDouble()));
            break;
        case QJsonValue::Bool:
            elementCreator(name, val.toBool() ? "true" : "false");
            break;
        case QJsonValue::Null:
            elementCreator(name);
            break;
        default:
            qDebug() << "Unhandled object type\n" << val.type();
        }
    }
}

void JsonTranslator::elementCreator(QString const& name, QString const& value) {
    if (value == "") {
        writer.writeEmptyElement(name);
    } else {
        writer.writeTextElement(name, value);
    }
}

