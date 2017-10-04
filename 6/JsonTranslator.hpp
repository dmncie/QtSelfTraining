#ifndef JSONTRANSLATOR_HPP
#define JSONTRANSLATOR_HPP

#include <QString>
#include <QJsonValue>
#include <QXmlStreamWriter>

class JsonTranslator
{
public:
    JsonTranslator();
    QString translate(QString const& input);
private:
    void parseObject(QJsonObject const& obj);
    void parseArray(QString const& name, QJsonArray const& obj);
    void parseValue(QString const& name, QJsonValue const& obj);
    void elementCreator(QString const& name, QString const& value = "");
private:
    QString output{};
    QXmlStreamWriter writer;

};

#endif // JSONTRANSLATOR_HPP
