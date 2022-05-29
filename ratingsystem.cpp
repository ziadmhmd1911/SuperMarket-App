#include "ratingsystem.h"
#include "ui_ratingsystem.h"
#include "CustomerMenu.h"
#include <QMessageBox>
RatingSystem::RatingSystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RatingSystem)
{
    ui->setupUi(this);
    if (supermarketobject.customers.empty()) {
    supermarketobject.readAllFiles();
    }

    for(int i = 0 ; i <this->supermarketobject.products.size() ; i++) {
        ui->productnames->addItem(this->supermarketobject.products[i].getName());
    }
    for (int i = 0 ; i <this->supermarketobject.sellers.size() ; i++) {
        ui->sellernames->addItem(this->supermarketobject.sellers[i].getName());
    }
      ui->label_3->setText("Welcome"+ this->supermarketobject.customers[supermarketobject.loggedInIndex].getName());
      ui->label_7->setText("Welcome"+ this->supermarketobject.customers[supermarketobject.loggedInIndex].getName());
      ui->tabWidget->setTabText(0,"Rate Product");
      ui->tabWidget->setTabText(1,"Rate Seller");
}

RatingSystem::~RatingSystem()
{
    delete ui;
}


void RatingSystem::on_subproductrate_clicked()
{
    QString productRate = ui->productrate->text();
    bool ok;
    float Rate = productRate.toFloat(&ok);
    if (Rate > 5 || Rate < 0) {
        QMessageBox::critical(this,"Rating" , "Your Rate Should Be Between 0.1 and 5.0");
    }
    else {
    int index = ui->productnames->currentIndex();
    QString proname = ui->productnames->currentText();
    this->supermarketobject.products[index].settotal_Rates(Rate);
    this->supermarketobject.products[index].setnumber_of_Rates();
    this->supermarketobject.products[index].setAverage_of_Rating();
    QMessageBox::information(this , "Rating" , "You Have Rated product" " "+proname+ " ""by "+productRate
                             +" ""And Product Overall is"+this->supermarketobject.products[index].getAverage_of_Rating());
    }
}


void RatingSystem::on_subsellerrate_clicked()
{
    QString sellerrate = ui->productrate->text();
    bool ok;
    float Rate = sellerrate.toFloat(&ok);
    if (Rate > 5 || Rate < 0) {
        QMessageBox::critical(this,"Rating" , "Your Rate Should Be Between 0.1 and 5.0");
    }
    else {
    int index = ui->sellernames->currentIndex();
    QString Selname = ui->sellernames->currentText();
    this->supermarketobject.sellers[index].settotal_Rates(Rate);
    this->supermarketobject.sellers[index].setnumber_of_Rates();
    this->supermarketobject.sellers[index].setAverage_of_Rating();
    QMessageBox::information(this , "Rating" , "You Have Rated seller" " "+Selname+ " ""by "+sellerrate
                             +" ""And Seller Overall is"" "+this->supermarketobject.sellers[index].getAverage_of_Rating());
}
}


void RatingSystem::on_pushButton_2_clicked()
{
    this->supermarketobject.writeAllFiles();
    this->hide();
    CustomerMenu cusmenu;
    cusmenu.setModal(true);
    cusmenu.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    cusmenu.exec();
}

