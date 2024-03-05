#ifndef SORTFACTORY_H
#define SORTFACTORY_H

#include "abstractfactory.h"

class SortFactory : public AbstractFactory
{
public:
    SortFactory();
    Sort* chooseSort(QString sortType, QList<Transaction *> t);
private:
};


#endif // SORTFACTORY_H
