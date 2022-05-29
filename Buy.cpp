#include "Buy.h"
#include "Search.h"
#include "recipet.h"
#include "ui_buy.h"
#include "CustomerMenu.h"
#include <QMessageBox>
#include <QSplashScreen>
#include <QTimer>
Buy::Buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buy)
{
    ui->setupUi(this);
    supermarketobject.readAllFiles();
    QPixmap bkgnd("D:/qt/login.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Buy::~Buy()
{
    delete ui;
}



// View All Products
void Buy::on_view_clicked()
{
    ui->comboBox->clear();
    for (int i=0 ; i < this->supermarketobject.products.size() ; i++) {
        ui->comboBox->addItem(this->supermarketobject.products[i].getName());
}
}


void Buy::on_pushButton_clicked()
{
    int x = ui->comboBox->currentIndex();
    for (int i = 0 ; i< this->supermarketobject.products.size() ; i++) {
    ui->name->setText(this->supermarketobject.products[x].getName());
    ui->quantity->setText(this->supermarketobject.products[x].getQuantity());
    ui->category->setText(this->supermarketobject.products[x].getCategory());
    ui->price->setText(this->supermarketobject.products[x].getPrice());
    ui->Rate->setText(QString::number(this->supermarketobject.products[x].getAverage_of_Rating()));
}
}


void Buy::on_pushButton_3_clicked()
{
    this->hide();
    Search search;
    search.setModal(true);
    search.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    search.exec();
}


void Buy::on_pushButton_4_clicked()
{
    this->hide();
    CustomerMenu cusmenu;
    cusmenu.setModal(true);
    cusmenu.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    cusmenu.exec();
}

