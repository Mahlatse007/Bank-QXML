#include "transactionlist.h"

TransactionList* TransactionList::onlyInstance = NULL;

TransactionList* TransactionList::getInstance()
{
    if (onlyInstance == NULL)
        onlyInstance = new TransactionList;
    return onlyInstance;
}

TransactionList::TransactionList()
{
}

TransactionList::~TransactionList()
{
    qDeleteAll(transactionList);
    transactionList.clear();
}

void TransactionList::addTransaction(Transaction *t)
{
    transactionList.append(t);
}

QList<Transaction*> TransactionList::returnList()
{
    return transactionList;
}

QString TransactionList::toString() const
{
    QString strlist;
    foreach (Transaction *t, transactionList)
        strlist.append(QString(t->toString() + "\n"));
    return strlist;
}

void TransactionList::clear()
{
    qDeleteAll(transactionList);
    transactionList.clear();
}
