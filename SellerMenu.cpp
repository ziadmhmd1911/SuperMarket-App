#include "SellerMenu.h"
#include "LoginMenu.h"
#include "selleredit.h"
#include "ui_sellermenu.h"
#include "Product.h"
#include "SuperMarket.h"
#include "Seller.h"
#include <QMessageBox>
SellerMenu::SellerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerMenu)
{
    ui->setupUi(this);
    supermarketobject.readAllFiles();
    QPixmap bkgnd("D:/qt/login.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

SellerMenu::~SellerMenu()
{
    delete ui;
}

void SellerMenu::on_pushButton_clicked()
{
//    if (!this->supermarketobject.sellers.empty()) {
//        this->supermarketobject.readAllFiles();
//    }
//    if (this->supermarketobject.customers.empty()) {
//        this->supermarketobject.readAllFiles();
//    }
    QString name;
    QString price;
    QString category;
    QString quantity;

    name = ui->productname->text();
    price = ui->productprice->text();
    category = ui->productcategory->text();
    quantity = ui->productquantity->text();


    bool flag = false;

    for (int i = 0 ; i<this->supermarketobject.products.size() ; i++) {
        if(this->supermarketobject.products[i].getName() == name)
            flag = true;
    }
    if (flag) {
        QMessageBox::StandardButton reply = QMessageBox::question(
                    this , "Adding Product" , "Product Already Exists, Do you want to edit it?" ,
                    QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            this->hide();
            SellerEdit se;
            se.setModal(true);
            se.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
            se.exec();
        }
        else {
            QMessageBox::information(this , "Adding Product" , "Product Still the same");
        }

    }
    else {
        QMessageBox::information(this , "Adding Product" , "Product Added");
        QString id = supermarketobject.generateId();
        QString ssid = supermarketobject.sellers[supermarketobject.loggedInIndex].getId();
        Product temp(id , ssid , quantity , price , name , category,0,0,0);
        this->supermarketobject.products.push_back(temp);
        //move this line when clicking a button
        this->supermarketobject.writeToFileFromProduct();
        ui->productname->clear();
        ui->productprice->clear();
        ui->productcategory->clear();
        ui->productquantity->clear();
    }


}


void SellerMenu::on_pushButton_2_clicked()
{
    this->supermarketobject.writeAllFiles();
    this->hide();
    loginmenu login;
    login.setModal(true);
    login.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    login.exec();
}


void SellerMenu::on_pushButton_3_clicked()
{
    this->hide();
    SellerEdit se;
    se.setModal(true);
    se.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    se.exec();
}

