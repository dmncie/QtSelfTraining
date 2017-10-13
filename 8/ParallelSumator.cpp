#include "ParallelSumCalculator.hpp"

ParallelSumCalculator::ParallelSumCalculator() :
numberOfRunnables{static_cast<unsigned int>(QThreadPool::globalInstance()->maxThreadCount())}
{}

void ParallelSumCalculator::createRunnables(unsigned int workload, Parallel::DataVec const& v) {
    for (unsigned int i = 0; i < numberOfRunnables; ++i) {
        if ((i+1) < numberOfRunnables) {
            runnables.emplace_back(std::make_unique<Parallel::SumTask>(
                                       v.cbegin() + i * workload,
                                       v.cbegin() + (i + 1) * workload));
        } else {
            runnables.emplace_back(std::make_unique<Parallel::SumTask>(
                                       v.cbegin() + i * workload,
                                       v.cend()));
        }
    }

    connect(QThreadPool::globalInstance(), &QThreadPool::activeThreadCount, this, &ParallelSumCalculator::)

}


void ParallelSumCalculator::compute(Parallel::DataVec const& v) {
    createRunnables(v.size()/numberOfRunnables, v);

    for(auto const& r : runnables ) {
        r->setAutoDelete(false);
        QThreadPool::globalInstance()->start(r.get());
    }

    QThreadPool::globalInstance()->waitForDone();

    int sum{};
    for(auto const& r : runnables ) {
        sum += r->getPartialSum();
    }
}
