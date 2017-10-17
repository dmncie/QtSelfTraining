#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTranslator>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("12_" + QLocale::system().name(), ":/translations/");
    app.installTranslator(&qtTranslator);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
