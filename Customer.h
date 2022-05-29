//
// Created by Ziad on 4/24/2022.
//

#ifndef DATASTRUCTURE_CUSTOMER_H
#define DATASTRUCTURE_CUSTOMER_H
#include <iostream>
#include "Cart.h"
#include "Product.h"
#include <vector>
#include "qlocale.h"
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>

using namespace std ;
class Customer {
public:
    QString id ;
    QString phone_number ;
    QString address;
    QString email ;
    QString password;
    QString name;
public:
    Cart customer_cart;


public:
    Customer(QString id, QString phoneNumber, QString password , QString address, QString email, QString name);

    QString getPassword();

    void setPassword(QString password);

    QString getId() ;

    void setId(QString id);

    QString getPhoneNumber() ;

    void setPhoneNumber(QString phoneNumber);

    QString getAddress() ;

    void setAddress( QString address);

    QString getEmail() ;

    void setEmail( QString email);

    QString getName() ;

    void setName( QString name);

};
#endif //DATASTRUCTURE_CUSTOMER_H
