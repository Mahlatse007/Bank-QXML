#include "sortfactory.h"
#include "sortselection.h"
#include "sortinsertion.h"

SortFactory::SortFactory()
{}

Sort* SortFactory::chooseSort(QString sortType, QList<Transaction*> t)
{
    if (sortType == "Selection")
        return new SelectionSort(t);
    else if (sortType == "Insertion")
        return new InsertionSort(t);
    return NULL;
}
