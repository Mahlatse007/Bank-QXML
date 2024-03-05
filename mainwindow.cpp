#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      layout(new QGridLayout),
      thisDate(QDate::currentDate()),
      date_l(new QLabel("Date")),
      showDate_l(new QLabel(thisDate.toString())),
      amount_l(new QLabel("Amount")),
      enterAmount(new QDoubleSpinBox()),
      deposit_b(new QPushButton("Deposit")),
      withdrawal_b(new QPushButton("Withdrawal")),
      file_b(new QPushButton("To file")),
      sortType(new QComboBox()),
      sort_b(new QPushButton("Sort")),
      read_b(new QPushButton("Read"))
{
    setWindowTitle("Banking transactions");
    resize(350, 100);

    // Setup layout
    layout->addWidget(date_l, 0, 0);
    layout->addWidget(showDate_l, 0, 1);
    layout->addWidget(amount_l, 1, 0);
    layout->addWidget(enterAmount, 1, 1);
    layout->addWidget(deposit_b, 2, 0);
    layout->addWidget(withdrawal_b, 3, 0);
    layout->addWidget(file_b, 2, 1);
    layout->addWidget(sortType, 4, 0);
    layout->addWidget(sort_b, 4, 1);
    layout->addWidget(read_b, 3, 1);

    enterAmount->setRange(0.00,9999.99);
    sortType->addItem("Selection");
    sortType->addItem("Insertion");

    setLayout(layout);

    // Connect signals and slots
    connect(deposit_b, SIGNAL(clicked()), this, SLOT(clickedDeposit()));
    connect(withdrawal_b, SIGNAL(clicked()), this, SLOT(clickedWithdrawal()));
    connect(file_b, SIGNAL(clicked()), this, SLOT(clickedFile()));
    connect(sort_b, SIGNAL(clicked()), this, SLOT(clickedSort()));
    connect(read_b, SIGNAL(clicked()), this, SLOT(clickedRead()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::clickedDeposit()
{
    th.makeDeposit(enterAmount->value());
    enterAmount->setValue(0);
}

void MainWindow::clickedWithdrawal()
{
    th.makeWithdrawal(enterAmount->value());
    enterAmount->setValue(0);
}

void MainWindow::clickedFile()
{
    bool success(th.writeToFile());
    if (success)
        QMessageBox::information(this, "Write to file", "Transactions successfully written to file");
    else
        QMessageBox::information(this, "Write to file", "Transactions not successfully written to file");
}

void MainWindow::clickedSort()
{
    QString type(sortType->currentText());
    bool success(th.doSort(type));
    if (!success)
        QMessageBox::information(this, "Sort failure", "Sort type not recognised");
}

void MainWindow::clickedRead()
{
    bool success(th.doRead());
    if (!success)
        QMessageBox::information(this, "Read file", "Transactions not successfully read from file");
}
