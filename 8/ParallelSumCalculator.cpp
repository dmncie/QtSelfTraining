#include "ParallelSumCalculator.hpp"
#include "SumCalculator.hpp"
#include <QThreadPool>

ParallelSumCalculator::ParallelSumCalculator(QObject* parent) :
    QObject(parent),
    numberOfThreads{1},
    finishedThreads{0},
    result{0}
{}

void ParallelSumCalculator::createThreads(int workload, Parallel::DataVec const& v) {
    for (int i = 0; i < numberOfThreads; ++i) {
        Parallel::SumTask* thread = new Parallel::SumTask(
                    v.cbegin() + i * workload,
                    ((i + 1) < numberOfThreads) ? v.cbegin() + (i + 1) * workload : v.cend(),
                    this);

        connect(thread, &SignalsSlots::finished,
                this, &ParallelSumCalculator::threadFinished);

        //        connect(thread, &SignalsSlots::finished,
        //                thread, &QObject::deleteLater);

        threads.push_back(thread);
    }
}

void ParallelSumCalculator::adjustNumberOfThread(int dataSize) {
    if (dataSize < 100) {
        numberOfThreads = 1;
    } else if (dataSize < 1000) {
        numberOfThreads = 2;
    } else if (dataSize < 100-0) {
        numberOfThreads = 4;
    } else {
        numberOfThreads = QThreadPool::globalInstance()->maxThreadCount();
    }
}

void ParallelSumCalculator::compute(Parallel::DataVec const& v) {
    cleanUp();
    adjustNumberOfThread(v.size());
    createThreads(v.size() / numberOfThreads, v);
    for (auto const& thread : threads) {
        thread->start();
    }
}

void ParallelSumCalculator::updateDataVector(Parallel::DataVec& vec) {
    compute(vec);
}

void ParallelSumCalculator::threadFinished(int partialSum) {
    finishedThreads++;
    result += partialSum;

    emit progressChanged(finishedThreads * 100 / numberOfThreads);

    if (finishedThreads == numberOfThreads) {
        emit resultComputed(result);
        cleanUp();
    }
}

void ParallelSumCalculator::cleanUp() {
    for (auto const& thread : threads) {
        if (thread && thread->isRunning()) {
            thread->quit();
            thread->wait();
        }
        delete thread;
    }

    threads.clear();
    result = 0;
    finishedThreads = 0;
}
