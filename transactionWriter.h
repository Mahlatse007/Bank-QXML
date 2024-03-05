#ifndef TRANSACTIONWRITER_H
#define TRANSACTIONWRITER_H

#include <QDomDocument>
#include "transaction.h"

class TransactionWriter
{
public:
    TransactionWriter();
    void addTransaction(Transaction *t);
    QDomDocument getDoc() const;
private:
    QDomDocument doc;
    QDomElement rootElement;
};

#endif // TRANSACTIONWRITER_H
