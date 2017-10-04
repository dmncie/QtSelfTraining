#include "JsonTranslatorWAttr.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

JsonTranslatorWAttr::JsonTranslatorWAttr() :
    output{},
    writer{&output}
{
    writer.setAutoFormatting(true);
}


QString JsonTranslatorWAttr::translate(QString const& input) {
    QJsonDocument doc(QJsonDocument::fromJson(input.toUtf8()));
    output.clear();
    // check validity of the document
    if(!doc.isNull()) {
        if(doc.isObject()) {
            insideElement = false;
            writer.writeStartDocument();
            parseObject(doc.object());
            writer.writeEndDocument();
        } else {
            qDebug() << "Document is not an object";
        }
    } else {
        qDebug() << "Invalid JSON...\n" << input;
    }

    return output;
}

void JsonTranslatorWAttr::parseObject(QJsonObject const& obj) {
    for (auto const& s : obj.keys()) {
        parseValue(s, obj[s]);
    }
}

void JsonTranslatorWAttr::parseArray(QString const& name, QJsonArray const& arr) {
    insideElement = false;
    for (auto const& a : arr) {
        parseValue(name, a);
    }
}

void JsonTranslatorWAttr::parseValue(QString const& name, QJsonValue const& val) {
    if (val.isObject()) {
        writer.writeStartElement(name);
        insideElement=true;
        parseObject(val.toObject());
        writer.writeEndElement();
        insideElement=false;
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

void JsonTranslatorWAttr::elementCreator(QString const& name, QString const& value) {
    if (insideElement) {
        writer.writeAttribute(name, value);
    } else if (value == "") {
        writer.writeEmptyElement(name);
    } else {
        writer.writeTextElement(name, value);
    }
}

