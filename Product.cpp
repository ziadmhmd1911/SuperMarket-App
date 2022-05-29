//
// Created by Ziad on 4/24/2022.
//

#include "Product.h"
Product::Product(QString id, QString sellerId, QString quantity, QString price, QString name, QString category,
                 float x , float y , float z)
{
    this->id = id;
    this->seller_id = sellerId;
    this->quantity = quantity;
    this->price = price;
    this->name = name;
    this->category = category;
    this->number_of_Rates = y;
    this->Average_of_Rating = z;
    this->total_Rates = x;
}

QString Product::getId() {
    return id;
}

void Product::setId(QString id) {
    Product::id = id;
}

QString Product::getSellerId()  {
    return seller_id;
}

void Product::setSellerId(QString sellerId) {
    seller_id = sellerId;
}

QString Product::getQuantity()  {
    return quantity;
}

void Product::setQuantity(QString quantity) {
    Product::quantity = quantity;
}

QString Product::getPrice()  {
    return price;
}

void Product::setPrice(QString price) {
    Product::price = price;
}

QString Product::getName()  {
    return name;
}

void Product::setName(QString name) {
    Product::name = name;
}

QString Product::getCategory()  {
    return category;
}

void Product::setCategory( QString category) {
    Product::category = category;
}

void Product::settotal_Rates (float total_Rates){
    Product::total_Rates += total_Rates;
}

void Product::setnumber_of_Rates (){
    Product::number_of_Rates = ++Product::number_of_Rates;
}

void Product::setAverage_of_Rating (){
    Product::Average_of_Rating = total_Rates/number_of_Rates;
}

float Product::gettotal_Rates(){
    return total_Rates;
}

float Product::getnumber_of_Rates(){
    return number_of_Rates;
}

float Product::getAverage_of_Rating(){
    return Average_of_Rating;
}



