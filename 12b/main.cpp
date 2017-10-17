#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "QmlTranslator.hpp"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QmlTranslator qmlTranslator;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("qmlTranslator", &qmlTranslator);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
