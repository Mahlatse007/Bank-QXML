#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "transactionlist.h"
#include "sort.h"
#include "transactionReader.h"

class TransactionHandler
{
public:
    TransactionHandler();
    ~TransactionHandler();
    void makeDeposit(double a);
    void makeWithdrawal(double a);
    bool writeToFile();
    bool doSort(QString type);
    bool doRead();

private:
    TransactionList* tList;
    Sort* mySort;
};

#endif // TRANSACTIONHANDLER_H
