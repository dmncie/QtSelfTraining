#ifndef SORTEDLAYOUT_HPP
#define SORTEDLAYOUT_HPP

#include <QLayout>

class SortedLayout : public QLayout
{
    Q_PROPERTY(Predicate predicate READ predicate WRITE setPredicate)
public:
    enum class Predicate {
        Width,
        Height
    };

    Q_ENUM(Predicate)

    explicit SortedLayout(QWidget *parent): QLayout(parent) {}
    SortedLayout(): QLayout() {}
    ~SortedLayout();
    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem* itemAt(int) const;
    QLayoutItem* takeAt(int);
    void setGeometry(const QRect &rect);

    void setPredicate(Predicate p);
    Predicate predicate() const;
private:
    void sort();
    Predicate m_predicate{Predicate::Width};
    QList<QLayoutItem*> items;
};

#endif // SORTEDLAYOUT_HPP
