#include "transactionReader.h"

#include <QDebug>
#include <QFile>

TransactionReader::TransactionReader()
{
}

TransactionReader::~TransactionReader()
{
}

QList<Transaction*> TransactionReader::getList(QString f)
{
    //parse file
    QFile file(f);
    file.open(QIODevice::ReadOnly);
    reader.setDevice(&file);
    bool collect(false);

    while (!reader.atEnd())
    {
        QXmlStreamReader::TokenType tt = reader.readNext();
        switch (tt)
        {
            case QXmlStreamReader::StartElement:
            {
                if (reader.name().toString()=="date" ||
                        reader.name().toString()=="time" ||
                        reader.name().toString()=="amount" ||
                        reader.name().toString()=="type")
                {
                    collect = true;
                }
                break;
            }
            case QXmlStreamReader::Characters:
            {
                if (collect)
                    details << reader.text().toString().trimmed();
                break;
            }
            case QXmlStreamReader::EndElement:
            {
                if (reader.name().toString()=="date" ||
                    reader.name().toString()=="time" ||
                    reader.name().toString()=="amount" ||
                    reader.name().toString()=="type")
                {
                    collect=false;
                }
                else if (reader.name().toString()=="transaction")
                {
                    createTransaction();
                }
                break;
            }
            default:
                break;
        }
    }
    file.close();

    return transactionList;
}

void TransactionReader::createTransaction()
{
    Transaction *t = new Transaction();
    QStringList data = details.at(0).split("-");
    t->setDate(QDate(data.at(0).toInt(),data.at(1).toInt(),data.at(2).toInt()));
    data = details.at(1).split(":");
    t->setTime(QTime(data.at(0).toInt(),data.at(1).toInt(),data.at(2).toInt()));
    t->setAmount(details.at(2).toDouble());
    t->setType(details.at(3));
    transactionList.append(t);
    details.clear();
}
