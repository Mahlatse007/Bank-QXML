#ifndef SORT_H
#define SORT_H

#include <QList>
#include "transaction.h"

class Sort
{
public:
    Sort(QList<Transaction*> t);
    virtual ~Sort();
    virtual void sort() = 0;
    QList<Transaction*> getList();
protected:
    QList<Transaction*> sortList;
};

#endif // SORT_H
