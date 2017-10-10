#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <MainWindow.hpp>
#include <ParallelSumCalculator.hpp>
#include <QThreadPool>

const int maxThreadCount = 64;


int parseArguments(QCoreApplication const& app, QCommandLineParser& parser) {
    parser.process(app);
    const QStringList args = parser.positionalArguments();

    bool ok{};
    int limit = args.at(0).toInt(&ok);

    if (!ok) {
        throw std::invalid_argument("Invalid argument. Expected an integer.");
    }

    return limit;
}

void setupArgumentParser(QCommandLineParser& parser) {
    parser.setApplicationDescription("Sums N numbers in parallel runnables");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("N", QCoreApplication::translate("N", "Number of elements inside and array."));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("ParallelSumCalculator");
    QApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    setupArgumentParser(parser);

    MainWindow w{};
    QThreadPool::globalInstance()->setMaxThreadCount(maxThreadCount);
    ParallelSumCalculator p{};

    QObject::connect(&p, &ParallelSumCalculator::progressChanged, &w, &MainWindow::updateProgress);
    QObject::connect(&p, &ParallelSumCalculator::resultComputed, &w, &MainWindow::updateResult);
    QObject::connect(&w, &MainWindow::dataVectorChanged, &p, &ParallelSumCalculator::updateDataVector);

    w.show();

    try {
        int limit = parseArguments(app, parser);
        w.intializeVec(limit);
    } catch (std::invalid_argument e) {
        qDebug() << "Error: " << e.what();
    }

    return app.exec();
}
