#ifndef SORTSELECTION_H
#define SORTSELECTION_H

#include "sort.h"

class SelectionSort : public Sort
{
public:
    SelectionSort(QList<Transaction *> t);
    void sort();

private:
    void swap(int first, int second);
    int minLocation(int first, int last);
};

#endif // SORTSELECTION_H
