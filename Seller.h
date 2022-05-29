//
// Created by Ziad on 4/24/2022.
//

#ifndef DATASTRUCTURE_SELLER_H
#define DATASTRUCTURE_SELLER_H
#include <string>
#include "qlocale.h"
#include <fstream>
#include <string>
#include <QFile>
#include <QTextStream>
using namespace std ;
class Seller {
private:
    QString id;
    QString name;
    QString email;
    QString password;
    float total_Rates; // 3dd kol el rates
    float number_of_Rates; // 3dd el nas elli 3mlo rate
    float Average_of_Rating; // Elrate nafso
public:
    Seller(QString id,  QString name,  QString email , QString password , float total_Rates , float number_of_Rates , float Average_of_Rating);

    Seller();

    QString getId() ;

    void setId(QString id);

    QString getName() ;

    void setName(QString name);

    QString getEmail() ;

    QString getPassword() ;

    void setPassword(QString password);


    void setEmail(QString email);

    void sellerLogin(QString email , QString id);

    float gettotal_Rates();

    void settotal_Rates(float total_Rates);

    float getnumber_of_Rates();

    void setnumber_of_Rates();

    float getAverage_of_Rating();

    void setAverage_of_Rating();
};
#endif //DATASTRUCTURE_SELLER_H
