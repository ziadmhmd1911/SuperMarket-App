#include "Search.h"
#include "recipet.h"
#include "ui_search.h"
#include <CustomerMenu.h>
#include <vector>
#include <QString>
#include "SuperMarket.h"
#include <QTreeWidget>
#include <QMessageBox>
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    supermarketobject.readAllFiles();
    QPixmap bkgnd("D:/qt/login.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    ui->comboBox->clear();
    //search
    QString searchname;
    QString results ;
    bool flag = false;
    searchname = ui->searching->text();
    if(ui->radioButton->isChecked())
    {
        for(int i = 0 ; i < supermarketobject.products.size() ; i++)
                {
                    if(supermarketobject.products[i].getCategory() == searchname)
                    {
                        flag = true;
                        results += supermarketobject.products[i].getName() + " ";
                        ui->comboBox->addItem(results);
                        results.clear();
                    }
                }
        if(flag){
            QMessageBox::information(this , "Searching" , searchname+"""Added To combo box");
        }
        else if(!flag) {
            QMessageBox::critical(this, "Searching" , searchname+"""Not Exist At SuperMarket");
        }

    }
    else if(ui->radioButton_2->isChecked())
    {
        for(int i = 0 ; i < supermarketobject.products.size() ; i++)
                {
                    if(supermarketobject.products[i].getName() == searchname)
                    {
                        flag = true;
                        results += supermarketobject.products[i].getName();
                        ui->comboBox->addItem(results);
                        results.clear();
                    }
                }
        if(flag){
            QMessageBox::information(this , "Searching" , searchname+"""Added To combo box");
        }
        else if(!flag) {
            QMessageBox::critical(this, "Searching" , searchname+"""Not Exist At SuperMarket");
        }
    }
}

void Search::on_pushButton_2_clicked()
{
    //add
    //add product

    QString name;
    QString quantity;

     name = ui->addproduct->text();
     quantity = ui->addquantity->text();
       bool flag = true;
       bool ok;
       int quan = quantity.toInt(&ok);

       // enter name and quantity of product
       // if name found then check the quantity and compare them
       // if current quantity is less than product real quantity(can add) :
       //
     for(int i = 0 ; i < supermarketobject.products.size() ; i++)
     {
         int getquan = supermarketobject.products[i].getQuantity().toInt(&ok);
         int userquan;
         int index;
         if(supermarketobject.products[i].getName() == name)
         {
             if (quan <= getquan) {
             for(int j = 0 ; j < supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.size() ; j++)
             {
                 if(supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[j].getName() == name)
                 {
                     flag = false;
                     bool ok;
                     int nn = supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[j].getQuantity().toInt(&ok);
                     userquan = nn;
                     index = j;
                     break;
                 }
             }
         }
             else {
                 QMessageBox::information(this, "title" , "Over Available Amount");
                 break;
             }
             if(flag)
             { 
                 // product[i].getQuantity in an int and current input quantity in another int
                 // then int = productquantity - inputquantity then convert to QString again
                 // then product[i].setQuantity(result)
                 int sum = getquan - quan;
                 QString result = QString::number(sum);
                 supermarketobject.products[i].setQuantity(result);
                 this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.push_back(supermarketobject.products[i]);
                 supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.back().setQuantity(quantity);
                 QMessageBox::information(this, "title" , "Product" " "+name+"quantity" " "+quantity + " has added to your cart .");
             }
             else
             {
                 QMessageBox::information(this , "title" , "quantity increased by " " " + quantity);
                 userquan += quan;
                 QString quanuser = QString::number(userquan);
                 supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[index].setQuantity(quanuser);
                 int sum = getquan - quan;
                 QString result = QString::number(sum);
                 supermarketobject.products[i].setQuantity(result);
             }
             break;
         }

     }
     supermarketobject.writeToFileFromCustomer();
     supermarketobject.writeToFileFromSeller();
     supermarketobject.writeToFileFromProduct();
     supermarketobject.writeToFileFromCustomerCart();
     supermarketobject.writeindextofilefromvariable();
}

void Search::on_pushButton_4_clicked()
{
    this->hide();
    Recipet recipet;
    recipet.setModal(true);
    recipet.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    recipet.exec();
}




void Search::on_pushButton_3_clicked()
{
    this->hide();
    CustomerMenu cusmenu;
    cusmenu.setModal(true);
    cusmenu.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    cusmenu.exec();
}

