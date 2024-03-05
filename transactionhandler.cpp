#include "transactionhandler.h"
#include "sortfactory.h"
#include "transactionWriter.h"

#include <QTextStream>
#include <QFile>

QTextStream cout(stdout);

TransactionHandler::TransactionHandler()
{
    tList = TransactionList::getInstance();
}

TransactionHandler::~TransactionHandler()
{
    delete tList;
    delete mySort;
}

void TransactionHandler::makeDeposit(double a)
{
    Transaction* temp = new Transaction(QDate::currentDate(), QTime::currentTime(), a, Transaction::TransactionType(Transaction::sm_TransactionType.indexOf("Deposit")));
    tList->addTransaction(temp);
    cout << temp->toString() << Qt::endl;
}

void TransactionHandler::makeWithdrawal(double a)
{
    Transaction* temp = new Transaction(QDate::currentDate(), QTime::currentTime(), a, Transaction::TransactionType(Transaction::sm_TransactionType.indexOf("Withdrawal")));
    tList->addTransaction(temp);
    cout << temp->toString() << Qt::endl;
}

bool TransactionHandler::writeToFile()
{
    //write to file from q1
    QFile myFile("transactions.txt");
    if (!myFile.open(QIODevice::WriteOnly))
        return false;

    QTextStream toFile(&myFile);
    QList<Transaction*> transList = tList->returnList();

    for(int loop=0; loop<transList.size(); loop++)
        toFile << transList.at(loop)->toString() << Qt::endl;
    myFile.close();

    //q2 write to XML using DOM
    QFile myXMLFile2("transactions.xml");

    if (!myXMLFile2.open(QIODevice::WriteOnly))
        return false;

    QTextStream toXMLFile2(&myXMLFile2);
    TransactionWriter tw;

    for (int j=0; j<transList.size(); j++)
        tw.addTransaction(transList.at(j));

    // QDomDocument tempDoc = tw.getDoc();
    // toXMLFile2 << tempDoc.toString();
    toXMLFile2 << tw.getDoc().toString();

    myXMLFile2.close();

    return true;
}

bool TransactionHandler::doSort(QString type)
{
    AbstractFactory* sf;
    sf = new SortFactory();

    QList<Transaction*> transList = tList->returnList();
    mySort = sf->chooseSort(type, transList);
    if (mySort == NULL)
        return false;

    mySort->sort();

    transList = mySort->getList();

    delete sf;

    cout << "After sort: " << Qt::endl;
    for (int i = 0; i<transList.size(); i++)
        cout << transList.at(i)->toString() << Qt::endl;
    return true;
}


bool TransactionHandler::doRead()
{
    if (QFile::exists("transactions.xml"))
    {
        TransactionReader reader;
        QList<Transaction*> list = reader.getList("transactions.xml");
        foreach(Transaction* t, list)
            tList->addTransaction(t);
        cout << "After file read: " << Qt::endl;
        cout << tList->toString() << Qt::endl;
    }
    else
        return false;
    return true;
}
