#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QPushButton>
#include <QLibraryInfo>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load("myapp_" + QLocale::system().name());
    app.installTranslator(&myappTranslator);
    QPushButton hello(QPushButton::tr("Hello world!"));

    hello.resize(100, 30);
    hello.show();
    return app.exec();
}
