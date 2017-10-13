#ifndef ParallelSumCalculator_HPP
#define ParallelSumCalculator_HPP

#include <QObject>
#include <SumCalculator.hpp>
#include <vector>
#include <memory>

namespace Parallel {
using DataVec = std::vector<int>;
using SumTask = SumCalculator<DataVec::const_iterator>;
using ThreadVec = std::vector<Parallel::SumTask*>;
}

class ParallelSumCalculator : public QObject
{
    Q_OBJECT

public:
    explicit ParallelSumCalculator(QObject *parent = 0);
    void compute(Parallel::DataVec const& v);

public slots:
    void updateDataVector(Parallel::DataVec&);

signals:
    void progressChanged(int);
    void resultComputed(int);

private slots:
    void threadFinished(int);

private:
    void adjustNumberOfThread(int dataSize);
    void createThreads(int workload,  Parallel::DataVec const& v);
    void cleanUp();

private:
    int numberOfThreads;
    int finishedThreads;
    int result;
    Parallel::ThreadVec threads;
};

#endif // ParallelSumCalculator_HPP
