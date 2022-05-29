//
// Created by Ziad on 4/24/2022.
//

#include "Customer.h"


QString Customer::getId()  {
    return id;
}

void Customer::setId(QString id) {
    Customer::id = id;
}

QString Customer::getPhoneNumber()  {
    return phone_number;
}

void Customer::setPhoneNumber(QString phoneNumber) {
    phone_number = phoneNumber;
}

QString Customer::getAddress()  {
    return address;
}

void Customer::setAddress( QString address) {
    Customer::address = address;
}

QString Customer::getEmail()  {
    return email;
}

void Customer::setEmail( QString email) {
    Customer::email = email;
}

Customer::Customer(QString id, QString phoneNumber,QString password ,QString address, QString email, QString name) : id(id), phone_number(phoneNumber), address(address),
                                                                                                                              email(email), name(name),password(password) ,customer_cart() {}

QString Customer::getName()  {
    return name;
}

void Customer::setName( QString name) {
    Customer::name = name;
}

QString Customer::getPassword() {
    return password;
}

void Customer::setPassword(QString password) {
    Customer::password = password;
}
