#ifndef SORTINSERTION_H
#define SORTINSERTION_H

#include "sort.h"

class InsertionSort : public Sort
{
public:
    InsertionSort(QList<Transaction *> t);
    void sort();
};


#endif // SORTINSERTION_H
