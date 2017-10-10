#ifndef SUMCALCULATOR_HPP
#define SUMCALCULATOR_HPP

#include <QRunnable>
#include <QObject>

class SignalsSlots : public QObject
{
    Q_OBJECT

public:
    explicit SignalsSlots(QObject *parent = 0) :
        QObject(parent) {}

    virtual ~SignalsSlots()
    {}

signals:
    void finished(int);

};

template <class Iterator>
class SumCalculator : public QRunnable, public SignalsSlots
{
public:
    SumCalculator(Iterator first, Iterator last) :
        first{first},
        last{last}
    {}

    virtual void run() override {        
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
