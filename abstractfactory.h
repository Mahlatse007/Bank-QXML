#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "sort.h"
#include "transaction.h"

class AbstractFactory
{
public:
    virtual ~AbstractFactory();
    virtual Sort* chooseSort(QString sortType, QList<Transaction*> t) = 0;
};

#endif // ABSTRACTFACTORY_H
