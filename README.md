# Bank-QXML
Banking Application developed using QtCreator (C++)

It provides a graphical user interface (GUI) for managing banking transactions and includes various sorting algorithms for data manipulation.

Features:

Graphical user interface (GUI) built using Qt framework for user interaction.
Implements various sorting algorithms such as insertion sort and selection sort.
Allows users to perform banking transactions including deposits, withdrawals, and transfers.
Supports reading and writing transaction data from/to files.
Utilizes an abstract factory design pattern for creating sorting algorithms dynamically.

Components:

mainwindow.cpp and mainwindow.h: Implement the main window of the application.
sort.cpp and sort.h: Define the base class for sorting algorithms.
sortfactory.cpp and sortfactory.h: Implement the abstract factory for sorting algorithms.
sortinsertion.cpp and sortinsertion.h: Implement the insertion sort algorithm.
sortselection.cpp and sortselection.h: Implement the selection sort algorithm.
transaction.cpp and transaction.h: Define the transaction class for managing banking transactions.
transactionhandler.cpp and transactionhandler.h: Implement transaction handling functionalities.
transactionlist.cpp and transactionlist.h: Define a list data structure for managing transactions.
transactionReader.cpp, transactionWriter.cpp, transactionReader.h, and transactionWriter.h: Implement classes for reading and writing transaction data from/to files.
abstractfactory.cpp and abstractfactory.h: Implement the abstract factory pattern for creating sorting algorithms.
