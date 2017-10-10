#ifndef ParallelSumCalculator_HPP
#define ParallelSumCalculator_HPP

#include <QObject>
#include <SumCalculator.hpp>
#include <vector>
#include <memory>

namespace Parallel {
using DataVec = std::vector<int>;
using SumTask = SumCalculator<DataVec::const_iterator>;
using RunnableVec = std::vector<std::unique_ptr<SumTask>>;
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
    void runnableFinished(int);

private:
    void createRunnables(int workload,  Parallel::DataVec const& v);
    void cleanUp();

private:
    int numberOfRunnables;
    int finishedRunnables;
    int result;
    Parallel::RunnableVec runnables;
};

#endif // ParallelSumCalculator_HPP
