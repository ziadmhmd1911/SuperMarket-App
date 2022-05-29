//
// Created by Ziad on 4/28/2022.
//

#ifndef DATASTRUCTURE_SUPERMARKET_H
#define DATASTRUCTURE_SUPERMARKET_H
#include <vector>

#include "Seller.h"
#include "Customer.h"
#include "Product.h"
#include "qlocale.h"
#include "ui_mainwindow.h"
#include <QString>
class SuperMarket {
public:
    //vector<QString> strings;
    vector<Seller> sellers;
    vector<Customer> customers;
    vector<Product> products;
    //    This is used to directly access the logged in user (seller or customer) inside its vector
    //    if the second seller is logged in => loggedInIndex = 1 ;
    //    seller[loggedInIndex]. ay 7aga fe el functions ba2a
    int loggedInIndex;
    QString ordernumber;

    void readAllFiles();
    void writeAllFiles();
    void readFromFileIntoSeller();
    void readFromFileIntoProduct();
    void readFromFileIntoCustomer();

    void writeToFileFromCustomer();

    void writeToFileFromSeller();

    void writeToFileFromProduct();

       void readFromFileIntoCustomerCart();
       void writeToFileFromCustomerCart();
       void readindexfromfileintovariable();
       void writeindextofilefromvariable();
       void readindexfromfileordernumber();
       void writeindextofileordernumber();
       QString generateId();
};

#endif //DATASTRUCTURE_SUPERMARKET_H
