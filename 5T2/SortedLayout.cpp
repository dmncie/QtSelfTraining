#include "SortedLayout.hpp"
#include <QVBoxLayout>
#include <QDebug>

int SortedLayout::count() const {
    return items.size();
}

QLayoutItem* SortedLayout::itemAt(int idx) const {
    return items.value(idx);
}

QLayoutItem* SortedLayout::takeAt(int idx) {
    return idx >= 0 && idx < items.size() ? items.takeAt(idx) : 0;
}

void SortedLayout::addItem(QLayoutItem* item) {
    items.append(item);
}

void SortedLayout::sort() {
    if (predicate() == Predicate::Width) {
        std::sort(items.begin(),
                  items.end(),
                  [](auto const& a, auto const& b){
            return a->geometry().width() < b->geometry().width();
        });
    } else {
        std::sort(items.begin(),
                  items.end(),
                  [](auto const& a, auto const& b){
            return a->geometry().height() < b->geometry().height();
        });
    }
}

SortedLayout::~SortedLayout() {
    QLayoutItem* i;
    while ((i = takeAt(0))){
        delete i;
    }
}

void SortedLayout::setGeometry(const QRect &r) {
    QLayout::setGeometry(r);

    sort();

    if (items.size() == 0)
        return;

    int offset = 0;
    for (auto& item : items) {
        QRect geom(r.x(), r.y() + offset, item->minimumSize().width(), item->geometry().height());
        offset += item->geometry().height() + spacing();
        item->setGeometry(geom);
    }
}

QSize SortedLayout::sizeHint() const {
    QSize size;
    for (auto const& item : items)
        size = size.expandedTo(item->sizeHint());

    for (auto const& item : items)
        size += QSize(0, item->sizeHint().height());

    qDebug() << "Size hint: " << size.width() << " x " << size.height();
    return size;
}

QSize SortedLayout::minimumSize() const {
    QSize size;
    for (auto const& item : items)
        size = size.expandedTo(item->minimumSize());

    for (auto const& item : items)
        size += QSize(0, item->minimumSize().height());

    qDebug() << "Minimum size: " << size.width() << " x " << size.height();
    return size;
}

void SortedLayout::setPredicate(Predicate p) {
    m_predicate = p;
}

SortedLayout::Predicate SortedLayout::predicate() const {
    return m_predicate;
}
