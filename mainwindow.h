#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDate>
#include <QTime>
#include <QDoubleSpinBox>
#include <QMessageBox>
#include <QComboBox>

#include "transactionhandler.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void clickedDeposit();
    void clickedWithdrawal();
    void clickedFile();
    void clickedSort();
    void clickedRead();

private:
    QGridLayout* layout;

    QDate thisDate;
    QTime thisTime;

    QLabel* date_l;
    QLabel* showDate_l;
    QLabel* amount_l;
    QDoubleSpinBox* enterAmount;
    QPushButton* deposit_b;
    QPushButton* withdrawal_b;
    QPushButton* file_b;
    QComboBox* sortType;
    QPushButton* sort_b;
    QPushButton* read_b;

    TransactionHandler th;
};

#endif // MAINWINDOW_H
