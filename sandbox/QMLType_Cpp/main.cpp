#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include "Message.hpp"

#include <QQmlComponent>
#include <QQmlProperty>
#include <QQuickView>
#include <QQuickItem>

void interactWithQMLObject_Component() {
    QQmlEngine engine;
    QQmlComponent component(&engine,
                            QUrl::fromLocalFile("MyItem.qml"));
    QObject*object = component.create();



    //    QQmlProperty(object, "width").write(500);

    object->setProperty("width", 500);



    QObject *rect = object->findChild<QObject*>("rect");
    if (rect)
        rect->setProperty("color", "red");



    //    qDebug() << "Property value:" << QQmlProperty::read(object, "someNumber").toInt();
    //    QQmlProperty::write(object, "someNumber", 5000);

    qDebug() << "Property value:" << object->property("someNumber").toInt();
    object->setProperty("someNumber", 100);



    delete object;
}

void interactWithQMLObject_QuickView() {
    QQuickView view;
    view.setSource(QUrl::fromLocalFile("MyItem.qml"));
    view.show();

    //    QObject* object = view.rootObject();
    //    QQuickItem* item = qobject_cast<QQuickItem*>(object);

    QQuickItem* item =  view.rootObject();

    item->setWidth(500);

    QObject *rect = object->findChild<QObject*>("rect");
    if (rect)
        rect->setProperty("color", "red");

    delete item;
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<Message>("com.company.messaging",1,0,"Message");

    engine.rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
