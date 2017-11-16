#include <QCoreApplication>
#include <QRunnable>
#include <QThread>
#include <QThreadPool>
#include <QDebug>

class HelloWorld : public QRunnable {
    virtual void run() override {
        qDebug() << "Hello world from thread " << QThread::currentThreadId();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto helloWorldTask = new HelloWorld();
    //QThreadPool takes ownership and deletes QRunnable
    QThreadPool::globalInstance()->start(helloWorldTask);
//    QThreadPool::globalInstance()->start(helloWorldTask); // Race condition, not recommended

    auto helloWorldTaskMulti = new HelloWorld();
    helloWorldTaskMulti->setAutoDelete(false);
    QThreadPool::globalInstance()->tryStart(helloWorldTaskMulti);
    QThreadPool::globalInstance()->tryStart(helloWorldTaskMulti);
    QThreadPool::globalInstance()->tryStart(helloWorldTaskMulti);
    QThreadPool::globalInstance()->tryStart(helloWorldTaskMulti);

    QThreadPool::globalInstance()->

    //QRunnable has to be explicitly removed
    delete helloWorldTaskMulti;

    return a.exec();
}
