#include "SuperMarket.h"
#include "mainwindow.h"
#include "qlocale.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "Product.h"

using namespace std;

// Reading Files
void SuperMarket::readFromFileIntoCustomerCart()
{
    QFile file("C:/Users/Zeyad/Documents/superfcis/customercart.txt");

         if (!file.open(QFile::ReadOnly | QFile::Text)) {
             cout << "file is closed" << endl;
         }
     QString line;
     QTextStream in(&file);
     QString customerid;
     QString productid;
     QString quantity;

    while(!in.atEnd())
    {
        line = in.readLine();
        customerid = line;
        for(int i = 0 ; i < customers.size() ; i++)
        {
            if(customers[i].getId() == line)
            {
                 line = in.readLine();
                 productid = line;
                 for(int j = 0 ; j < products.size() ; j++)
                 {
                     if(products[j].getId() == productid)
                     {
                           this->customers[i].customer_cart.cart_items.push_back(this->products[j]);

                           line = in.readLine();
                           quantity = line;

                        this->customers[i].customer_cart.cart_items.back().setQuantity(quantity);
                           line = in.readLine();
                           break;
                     }
                 }
            }

        }

    }
        file.close();
}
void SuperMarket::writeToFileFromCustomerCart()
{
    QFile file("C:/Users/Zeyad/Documents/superfcis/customercart.txt");
   if (!file.open(QFile::WriteOnly | QFile::Text)) {
       cout << "File is not opened" << endl;
   }
   QTextStream customerscartFile(&file);


    for (int i = 0; i < customers.size(); i++)
        {
            for (int j = 0; j < this->customers[i].customer_cart.cart_items.size(); j++)
            {
                   customerscartFile << customers[i].getId()<<endl;
                   customerscartFile << customers[i].customer_cart.cart_items[j].getId()<<endl;
                   customerscartFile << customers[i].customer_cart.cart_items[j].getQuantity()<<endl;
                     customerscartFile << " --------" << endl;
            }

        }

    file.flush();
    file.close();

}
void SuperMarket::readindexfromfileintovariable()
{
    QFile file("C:/Users/Zeyad/Documents/superfcis/loggedindex.txt");

         if (!file.open(QFile::ReadOnly | QFile::Text)) {
             cout << "file is closed" << endl;
         }
       QString line;
       QTextStream in(&file);

       line = in.readLine();
       bool ok;
       //int  num = quantity.toInt(&ok);
       int loggedInIndex = line.toInt(&ok);
        this->loggedInIndex = loggedInIndex;
        file.close();
}
void SuperMarket::writeindextofilefromvariable()
{
    QFile file("C:/Users/Zeyad/Documents/superfcis/loggedindex.txt");
   if (!file.open(QFile::WriteOnly | QFile::Text)) {
       cout << "File is not opened" << endl;
   }
   QTextStream index(&file);

   index << this->loggedInIndex << endl;


    file.flush();
    file.close();

}
void SuperMarket::readindexfromfileordernumber()
{
    QFile file("C:/Users/Zeyad/Documents/superfcis/ordernumber.txt");

         if (!file.open(QFile::ReadOnly | QFile::Text)) {
             cout << "file is closed" << endl;
         }
       QString line;
       QTextStream in(&file);

       line = in.readLine();
       this->ordernumber = line;
       file.close();
}
void SuperMarket::writeindextofileordernumber()
{
    QFile file("C:/Users/Zeyad/Documents/superfcis/ordernumber.txt");
   if (!file.open(QFile::WriteOnly | QFile::Text)) {
       cout << "File is not opened" << endl;
   }
   QTextStream index(&file);
   bool ok;
   int od = ordernumber.toInt(&ok);
   od++;
   index << od << endl;


   file.flush();
   file.close();

}
 void SuperMarket::readFromFileIntoCustomer()
 {
     QFile file("C:/Users/Zeyad/Documents/superfcis/customer.txt");

          if (!file.open(QFile::ReadOnly | QFile::Text)) {
              cout << "file is closed" << endl;
          }
      QString line;
      QTextStream in(&file);
      QString id;
      QString email;
      QString password;
      QString name;
      QString address;
      QString phone_number;

     while(!in.atEnd())
     {

         line = in.readLine();
         id = line;

         line = in.readLine();
         email = line;

         line = in.readLine();
         password = line;

         line = in.readLine();
         name = line;

         line = in.readLine();
         address = line;

         line = in.readLine();
         phone_number = line;

         line = in.readLine();

         Customer tempCustomer(id,phone_number,password,address,email,name);
         this->customers.push_back(tempCustomer);
     }
         file.close();
 }
 void SuperMarket::readFromFileIntoSeller()
 {
     QFile file("C:/Users/Zeyad/Documents/superfcis/seller.txt");

          if (!file.open(QFile::ReadOnly | QFile::Text)) {
              cout << "file is closed" << endl;
          }
      QString line;
      QTextStream in(&file);
      QString id;
      QString email;
      QString password;
      QString name;
      QString address;
     QString phone_number;
     float total_Rates;
     float Average_of_Rates;
     float number_of_Rates;
     bool ok;
     while(!in.atEnd())
     {

         line = in.readLine();
         id = line;

         line = in.readLine();
         email = line;

         line = in.readLine();
         password = line;

         line = in.readLine();
         name = line;

         line = in.readLine();
         total_Rates = line.toFloat(&ok);

         line = in.readLine();
         number_of_Rates = line.toFloat(&ok);

         line = in.readLine();
         Average_of_Rates = line.toFloat(&ok);

         line = in.readLine();

         Seller tempSeller(id,name,email,password,total_Rates,number_of_Rates,Average_of_Rates);
         this->sellers.push_back(tempSeller);
     }
         file.close();
 }
 void SuperMarket::readFromFileIntoProduct()
 {
     QFile file("C:/Users/Zeyad/Documents/superfcis/product.txt");

     if (!file.open(QFile::ReadOnly | QFile::Text)) {
         cout << "file is closed" << endl;
     }
     QString line;
     QTextStream in(&file);
     QString id;
     QString price;
     QString quantity;
     QString name;
     QString seller_id;
     QString category;
     float total_Rates;
     float Average_of_Rates;
     float number_of_Rates;
     bool ok;
while(!in.atEnd())
{

    line = in.readLine();
    id = line;

    line = in.readLine();
    name = line;

    line = in.readLine();
    price = line;

    line = in.readLine();
    quantity = line;

    line = in.readLine();
    category = line;

    line = in.readLine();
    seller_id = line;

    line = in.readLine();
    total_Rates = line.toFloat(&ok);

    line = in.readLine();
    number_of_Rates = line.toFloat(&ok);

    line = in.readLine();
    Average_of_Rates = line.toFloat(&ok);

    line = in.readLine();

    Product tempProduct(id,seller_id,quantity,price,name,category,total_Rates,number_of_Rates,Average_of_Rates);
    this->products.push_back(tempProduct);
}
    file.close();
}
 void SuperMarket::writeToFileFromCustomer()
 {
     QFile file("C:/Users/Zeyad/Documents/superfcis/customer.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        cout << "File is not opened" << endl;
    }
    QTextStream customersFile(&file);


     for (int i = 0; i < customers.size(); i++)
         {
             customersFile << customers[i].getId() << endl;
             customersFile << customers[i].getEmail() << endl;
             customersFile << customers[i].getPassword() << endl;
             customersFile << customers[i].getName() << endl;
             customersFile << customers[i].getAddress() << endl;
             customersFile << customers[i].getPhoneNumber() << endl;
             customersFile << "----------" << endl;
         }
     file.flush();
     file.close();

 }
 void SuperMarket::writeToFileFromSeller()
 {
     QFile file("C:/Users/Zeyad/Documents/superfcis/seller.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text | QFile::OpenMode())) {
        cout << "File is not opened" << endl;
    }
    QTextStream sellersFile(&file);


    for (int i = 0; i < sellers.size(); i++)
    {
                 sellersFile << sellers[i].getId() << endl;
                 sellersFile << sellers[i].getEmail() << endl;
                 sellersFile << sellers[i].getPassword() << endl;
                 sellersFile << sellers[i].getName() << endl;
                 sellersFile << sellers[i].gettotal_Rates() << endl;
                 sellersFile << sellers[i].getnumber_of_Rates() << endl;
                 sellersFile << sellers[i].getAverage_of_Rating() << endl;
                 sellersFile << "----------" << endl;
    }
     file.flush();
     file.close();

 }
 void SuperMarket::writeToFileFromProduct()
 {
     QFile file("C:/Users/Zeyad/Documents/superfcis/product.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        cout << "File is not opened" << endl;
    }
    QTextStream productsFile(&file);


    for (int i = 0; i < products.size(); i++)
             {
                 productsFile << products[i].getId() << endl;
                 productsFile << products[i].getName() << endl;
                 productsFile << products[i].getPrice() << endl;
                 productsFile << products[i].getQuantity() << endl;
                 productsFile << products[i].getCategory() << endl;
                 productsFile << products[i].getSellerId() << endl;
                 productsFile << products[i].gettotal_Rates() << endl;
                 productsFile << products[i].getnumber_of_Rates() << endl;
                 productsFile << products[i].getAverage_of_Rating() << endl;
                 productsFile << "--------------------" << endl;
             }
     file.flush();
     file.close();


 }
 //=================================================


 QString SuperMarket::generateId() {
     /*
     * GENERATE 16 BIT STRING WITH 0 - 9, , a-Z CHARACTERS
     * 0 - 9 ASCII CODE IS : 48 - 57 (1)
     * a - z ASCII CODE IS : 97 - 122 (3)
     */
     srand(time(0));
     QString id;
     int rand1 = 0, rand2 = 0;
     for (int i = 0; i < 12; i++) {
         rand1 = rand() % 2 + 1;
         switch (rand1) {
         case 1: {
             rand2 = rand() % 10 + 48;
             break;
         }
         case 2: {
             rand2 = rand() % 26 + 97;
             break;
         }

         }
         id += (char)rand2;
     }
     return id;
 }


 void SuperMarket::readAllFiles()
 {
     this->readFromFileIntoCustomer();
     this->readFromFileIntoSeller();
     this->readFromFileIntoProduct();
     this->readFromFileIntoCustomerCart();
     this->readindexfromfileintovariable();
     this->readindexfromfileordernumber();
 }

 void SuperMarket::writeAllFiles()
 {
     this->writeToFileFromCustomer();
     this->readFromFileIntoCustomerCart();
     this->writeToFileFromProduct();
     this->writeToFileFromSeller();
 }
