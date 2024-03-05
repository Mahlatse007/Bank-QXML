#include "transaction.h"

const QStringList Transaction::sm_TransactionType = (QStringList() << "Withdrawal" << "Deposit");

Transaction::Transaction()
{}

Transaction::~Transaction()
{}

Transaction::Transaction(QDate d, QTime t, double a, TransactionType tt):
        date(d), time(t), amount(a), type(tt)
{
}

QString Transaction::toString() const
{
    QString a(QString::number(amount));
    QString d(date.toString());
    QString t(time.toString());
    QString tt(sm_TransactionType.at(type));

    return QString(tt + ": R" + a + " on " + d + " at " + t);
}

QDate Transaction::getDate() const
{
    return date;
}

QTime Transaction::getTime() const
{
    return time;
}

double Transaction::getAmount() const{
    return amount;
}

QString Transaction::getType() const
{
    return Transaction::sm_TransactionType.at(type);
}

void Transaction::setDate(QDate d)
{
    date = d;
}

void Transaction::setTime(QTime t)
{
    time = t;
}

void Transaction::setAmount(double a)
{
    amount = a;
}

void Transaction::setType(QString t)
{
    type = Transaction::TransactionType(Transaction::sm_TransactionType.indexOf(t));
}
