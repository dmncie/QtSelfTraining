#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QXmlStreamWriter>
#include <QString>
#include <QByteArray>
#include <QDebug>

QString parseJsonObject(QJsonObject const& obj, QString name = "") {
    QString output;

    if (name != "" ) {
        output += "<" + name;
    }

    for (auto const& v : obj) {
        if (!v.isObject() && !v.isArray()) {
            output += v.toString();
        }
    }

    if (obj.isEmpty() && name != "") {
        output += "\\>";
    } else {
        if (name != "")
            output += ">";

        for (auto const& v : obj) {
            if (v.isObject()) {
                output + parseJsonObject(v.toObject());
            }
        }

        output += "<" + name + ">";
    }

    return output;
}

QString parseJsonArray(QJsonArray const& arr) {
    if (arr.isEmpty())
        return "";
    else
        return QString::number(arr.size());
}

QString jsonToXML(QString const& in) {
    QJsonDocument doc(QJsonDocument::fromJson(in.toUtf8()));
    QJsonObject obj;
    // check validity of the document
    if(!doc.isNull())    {
        if(doc.isObject())        {
            obj = doc.object();
            return parseJsonObject(obj);
        } else {
            qDebug() << "Document is not an object";
        }
    } else {
        qDebug() << "Invalid JSON...\n" << in;
    }

    return "";
}

#endif // TRANSLATOR_HPP
