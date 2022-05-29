#include "recipet.h"
#include "CustomerMenu.h"
#include "ui_recipet.h"
#include <Search.h>
#include <QTime>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
Recipet::Recipet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recipet)
{
    ui->setupUi(this);
    supermarketobject.readAllFiles();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this , SLOT(myfunction()));
    timer->start(0);
}

Recipet::~Recipet()
{
    delete ui;
}

void Recipet::myfunction() {
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_time->setText(time_text);
}



void Recipet::on_pushButton_clicked()
{
    ui->treeWidget->clear();

    ui->treeWidget->setColumnCount(5);
    QStringList lables;
    lables << "Product Name" << "Product Quantity" << "Product Price" << "Total Price" << "Product Rate";
    ui->treeWidget->setHeaderLabels(lables);

    if(!this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.empty())
    {
        for (int i=0 ; i<this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.size(); i++) {
            QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
            bool ok;
            int price = this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[i].getPrice().toInt(&ok);
            int quantity = this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[i].getQuantity().toInt(&ok);
            QString item_total_price = QString::number(price*quantity);
        root->setText(0 , this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[i].getName());
        root->setText(1 , this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[i].getQuantity());
        root->setText(2 , this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[i].getPrice());
        root->setText(3 , item_total_price);
        QString averagerate = QString::number(this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items[i].getAverage_of_Rating());
        root->setText(4, averagerate);
    }
        for(int i=0 ; i<this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.size();i++) {
            ui->lineEdit->setText(this->supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.calculate_total_price());
    }
            //Order Number
            ui->ordernum->setText(supermarketobject.ordernumber);

}
}


void Recipet::on_pushButton_2_clicked()
{
    if(supermarketobject.customers.empty())
    {
        supermarketobject.readFromFileIntoCustomer();
        supermarketobject.readFromFileIntoSeller();
        supermarketobject.readFromFileIntoProduct();
        supermarketobject.readFromFileIntoCustomerCart();
        supermarketobject.readindexfromfileintovariable();
        supermarketobject.readindexfromfileordernumber();
    }
    if (supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.empty()) {
        QMessageBox::StandardButton reply = QMessageBox::question(
                    this , "Viewing Recipet" , "Cart Is Empty, Go To Mark to buy?" ,
                    QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this->hide();
            Search search;
            search.setModal(true);
            search.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
            search.exec();
        }
    }
    else {
        supermarketobject.customers[supermarketobject.loggedInIndex].customer_cart.cart_items.clear();
        supermarketobject.writeToFileFromCustomerCart();
        supermarketobject.writeAllFiles();
        supermarketobject.writeindextofileordernumber();
        QMessageBox::information(this , "FCIS-MARKET" , "CONGRATS!!");
        this->hide();
        CustomerMenu cusmenu;
        cusmenu.setModal(true);
        cusmenu.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
        cusmenu.exec();
    }
}


void Recipet::on_pushButton_3_clicked()
{
    this->hide();
    CustomerMenu cusmenu;
    cusmenu.setModal(true);
    cusmenu.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    cusmenu.exec();
}

