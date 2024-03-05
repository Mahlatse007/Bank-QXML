#include "transactionWriter.h"

TransactionWriter::TransactionWriter()
{
    rootElement = doc.createElement("TransactionList");
    doc.appendChild(rootElement);
}

void TransactionWriter::addTransaction(Transaction* t)
{
    QDomElement transactionElement = doc.createElement("transaction");
    rootElement.appendChild(transactionElement);

    QDomElement dateElement = doc.createElement("date");
    QString strDate = t->getDate().toString("yyyy-MM-dd");
    QDomText dateText = doc.createTextNode(strDate);
    transactionElement.appendChild(dateElement);
    dateElement.appendChild(dateText);

    QDomElement timeElement = doc.createElement("time");
    QString strTime = t->getTime().toString();
    QDomText timeText = doc.createTextNode(strTime);
    transactionElement.appendChild(timeElement);
    timeElement.appendChild(timeText);

    QDomElement amountElement = doc.createElement("amount");
    QString strAmount = QString::number(t->getAmount());
    QDomText amountText = doc.createTextNode(strAmount);
    transactionElement.appendChild(amountElement);
    amountElement.appendChild(amountText);

    QDomElement typeElement = doc.createElement("type");
    QString strType = t->getType();
    QDomText typeText = doc.createTextNode(strType);
    transactionElement.appendChild(typeElement);
    typeElement.appendChild(typeText);
}

QDomDocument TransactionWriter::getDoc() const
{
    return doc;
}
