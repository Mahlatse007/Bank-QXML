#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include <QList>
#include "transaction.h"

class TransactionList
{
public:
    ~TransactionList();
    static TransactionList* getInstance();
    void addTransaction(Transaction* t);
    QList<Transaction*> returnList();
    QString toString() const;
    void clear();
private:
    TransactionList();
    static TransactionList* onlyInstance;
    QList<Transaction*> transactionList;
};

#endif // TRANSACTIONLIST_H
