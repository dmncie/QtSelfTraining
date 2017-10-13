#ifndef SUMCALCULATOR_HPP
#define SUMCALCULATOR_HPP

#include <QThread>
#include <QObject>

class SignalsSlots : public QThread
{
    Q_OBJECT

public:
    explicit SignalsSlots(QObject *parent = 0):
        QThread(parent)
    {}

    virtual ~SignalsSlots()
    {
        exit();
        wait();
    }

signals:
    void finished(int);

};

template <class Iterator>
class SumCalculator : public SignalsSlots
{
public:
    explicit SumCalculator(Iterator first, Iterator last, QObject *parent = 0) :
        SignalsSlots(parent),
        first{first},
        last{last}
    {}

public:
    void run() override {
        int sum{};
        while (first != last) {
            sum += *first;
            ++first;
        }

        emit finished(sum);
    }

private:
    Iterator first;
    Iterator last;
};

#endif // SUMCALCULATOR_HPP
