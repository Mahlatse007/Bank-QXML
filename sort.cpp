#include "sort.h"

Sort::Sort(QList<Transaction*> t)
{
    sortList.clear();
    for (int i = 0; i < t.size(); i++)
        sortList.append(t.at(i));
}

QList<Transaction*> Sort::getList()
{
    return sortList;
}

Sort::~Sort()
{
}
