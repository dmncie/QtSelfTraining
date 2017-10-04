#ifndef JSONTRANSLATORWATTR_HPP
#define JSONTRANSLATORWATTR_HPP

#include <QString>
#include <QJsonValue>
#include <QXmlStreamWriter>

class JsonTranslatorWAttr
{
public:
    JsonTranslatorWAttr();
    QString translate(QString const& input);
private:
    void parseObject(QJsonObject const& obj);
    void parseArray(QString const& name, QJsonArray const& obj);
    void parseValue(QString const& name, QJsonValue const& obj);
    void elementCreator(QString const& name, QString const& value = "");
private:
    bool insideElement{false};
    QString output{};
    QXmlStreamWriter writer;

};

#endif // JSONTRANSLATORWATTR_HPP
