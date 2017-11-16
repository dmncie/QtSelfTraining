#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Message.hpp"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Message msg;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("msg", &msg);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
