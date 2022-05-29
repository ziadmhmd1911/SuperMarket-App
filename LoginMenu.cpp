#include "LoginMenu.h"
#include "ui_loginmenu.h"
#include "SellerMenu.h"
#include "CustomerMenu.h"
#include <QMessageBox>
loginmenu::loginmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginmenu)
{
    ui->setupUi(this);
    supermarketobject.readAllFiles();
    QPixmap bkgnd("D:/qt/login.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

loginmenu::~loginmenu()
{
    delete ui;
}

void loginmenu::on_pushButton_clicked()
{
    QString email;
    QString password;

    email = ui->email->text();
    password = ui->password->text();

    if (ui->radioButton->isChecked()) {

        bool flag = false;


        for (int i = 0 ; i < this->supermarketobject.sellers.size() ; i++)
        {
            if(this->supermarketobject.sellers[i].getEmail() == email && this->supermarketobject.sellers[i].getPassword() == password)
            {
                flag = true;
                this->supermarketobject.loggedInIndex = i;
            }
        }

        if(flag)
        {
            QMessageBox::information(this , "Welcome" , "Welcome Seller" " " ""+ (email));
            this->hide();
            SellerMenu sellermenu;
            sellermenu.setModal(true);
            sellermenu.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
            sellermenu.exec();
        }
        else
        {
            QMessageBox::critical(this , "LOGIN" , "Incorrect Data!!!!");
        }
    }
    else if (ui->radioButton_2->isChecked()) {
        bool flag = false;
        for (int i = 0 ; i < this->supermarketobject.customers.size() ; i++)
        {
            if(this->supermarketobject.customers[i].getEmail() == email && this->supermarketobject.customers[i].getPassword() == password)
            {
                flag = true;
                this->supermarketobject.loggedInIndex = i;
            }
        }

        if(flag)
        {
            this->supermarketobject.writeindextofilefromvariable();
            QMessageBox::information(this , "Welcome" , "Welcome Customer" " "+email);
            this->hide();
            CustomerMenu cusmenu;
            cusmenu.setModal(true);
            cusmenu.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
            cusmenu.exec();
        }
        else
        {
            QMessageBox::critical(this , "LOGIN" , "Incorrect Data!!!!");
        }
    }
        else
    {
        QMessageBox::warning(this , "LOGIN" , "Please Choose Your Type");
    }
}

