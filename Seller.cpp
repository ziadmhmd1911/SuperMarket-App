//
// Created by Ziad on 4/24/2022.
//

#include "Seller.h"
#include <vector>
#include "qlocale.h"
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>
Seller::Seller(QString id, QString name, QString email , QString password, float x , float y , float z) : id(id), name(name), email(email),password(password), total_Rates(x), number_of_Rates(y), Average_of_Rating(z) {}

Seller::Seller() {
    id="";
    name = "";
    email = "";
}

QString Seller::getId()  {
    return this->id;
}

void Seller::setId(QString id) {
    Seller::id = id;
}

QString Seller::getName()  {
    return name;
}

void Seller::setName( QString name) {
    Seller::name = name;
}

QString Seller::getEmail()  {
    return email;
}

void Seller::setEmail( QString email) {
    Seller::email = email;
}
QString Seller::getPassword()  {
    return password;
}



void Seller::setPassword( QString password) {
    Seller::password = password;
}

void Seller::settotal_Rates (float total_Rates){
    Seller::total_Rates += total_Rates;
}

void Seller::setnumber_of_Rates (){
    ++Seller::number_of_Rates;
}

void Seller::setAverage_of_Rating (){
    Seller::Average_of_Rating = total_Rates/number_of_Rates;
}

float Seller::gettotal_Rates(){
    return total_Rates;
}

float Seller::getnumber_of_Rates(){
    return number_of_Rates;
}

float Seller::getAverage_of_Rating(){
    return Average_of_Rating;
}
