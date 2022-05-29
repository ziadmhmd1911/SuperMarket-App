//
// Created by Ziad on 4/24/2022.
//

#ifndef DATASTRUCTURE_PRODUCT_H
#define DATASTRUCTURE_PRODUCT_H
#include <string>
#include "qlocale.h"
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>
using namespace std ;

class Product {
public:
    QString id ;
    QString seller_id;
    QString quantity;
    QString price;
    QString name;
    QString category;
    float total_Rates; // 3dd kol el rates
    float number_of_Rates; // 3dd el nas elli 3mlo rate
    float Average_of_Rating; // Elrate nafso

public:
    Product(QString id, QString sellerId, QString quantity, QString price, QString name, QString category , float x , float y , float z);

    QString getId() ;

    void setId(QString id);

    QString getSellerId() ;

    void setSellerId(QString sellerId);

    QString getQuantity() ;

    void setQuantity(QString quantity);

    QString getPrice() ;

    void setPrice(QString price);

    QString getName() ;

    void setName(QString name);

    QString getCategory();

    void setCategory(QString category);

    float gettotal_Rates();

    void settotal_Rates(float total_Rates);

    float getnumber_of_Rates();

    void setnumber_of_Rates();

    float getAverage_of_Rating();

    void setAverage_of_Rating();
};
#endif //DATASTRUCTURE_PRODUCT_H
