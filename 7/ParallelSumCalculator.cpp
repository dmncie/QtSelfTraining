#include "ParallelSumCalculator.hpp"
#include "SumCalculator.hpp"
#include <QThreadPool>

ParallelSumCalculator::ParallelSumCalculator(QObject* parent) :
    QObject(parent),
    numberOfRunnables{QThreadPool::globalInstance()->maxThreadCount()},
    finishedRunnables{},
    result{}
{}

void ParallelSumCalculator::createRunnables(int workload, Parallel::DataVec const& v) {
    for (int i = 0; i < numberOfRunnables; ++i) {
        runnables.emplace_back(std::make_unique<Parallel::SumTask>(
                                   v.cbegin() + i * workload,
                                   ((i + 1) < numberOfRunnables)
                                   ? v.cbegin() + (i + 1) * workload
                                   : v.cend()));
    }

    for (auto const& r : runnables) {
        connect(r.get(), &SignalsSlots::finished, this, &ParallelSumCalculator::runnableFinished);
    }
}


void ParallelSumCalculator::compute(Parallel::DataVec const& v) {
    cleanUp();
    createRunnables(v.size() / numberOfRunnables, v);

    for(auto const& r : runnables ) {
        r->setAutoDelete(false);
        QThreadPool::globalInstance()->start(r.get());
    }
}

void ParallelSumCalculator::updateDataVector(Parallel::DataVec& vec) {
    compute(vec);
}

void ParallelSumCalculator::runnableFinished(int partialSum) {
    finishedRunnables++;
    result += partialSum;

    emit progressChanged(finishedRunnables * 100 / numberOfRunnables);

    if (finishedRunnables == numberOfRunnables) {
        emit resultComputed(result);
        cleanUp();
    }
}

void ParallelSumCalculator::cleanUp() {
    result = 0;
    finishedRunnables = 0;

    for (auto const& r : runnables) {
        disconnect(r.get(), 0, 0, 0);
    }

    QThreadPool::globalInstance()->clear();
    QThreadPool::globalInstance()->waitForDone();
    runnables.clear();
}
