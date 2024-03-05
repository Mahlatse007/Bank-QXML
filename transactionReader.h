#ifndef TRANSACTIONREADER_H
#define TRANSACTIONREADER_H

#include <QXmlStreamReader>
#include <QStringList>
#include <QList>
#include "transaction.h"

class TransactionReader
{
public:
    TransactionReader();
    ~TransactionReader();
    QList<Transaction*> getList(QString f);
private:
    QXmlStreamReader reader;
    QList<Transaction*> transactionList;
    QStringList details;

    void createTransaction();
};

#endif // TRANSACTIONREADER_H
