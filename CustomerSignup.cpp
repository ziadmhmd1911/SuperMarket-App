#include "CustomerSignup.h"
#include "LoginMenu.h"
#include "qvalidator.h"
#include "ui_customersignup.h"
#include "Customer.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QMainWindow>
#include <ui_mainwindow.h>
CustomerSignUp::CustomerSignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerSignUp)
{
    ui->setupUi(this);
    supermarketobject.readAllFiles();
    QPixmap bkgnd("D:/qt/login.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

CustomerSignUp::~CustomerSignUp()
{
    delete ui;
}

void CustomerSignUp::on_pushButton_clicked()
{
    QString name;
    QString address;
    QString phonenumber;
    QString email;
    QString password;
    bool flag = false;
    name = ui->customername->text();
    address = ui->customeraddress->text();
    phonenumber = ui->customerphonenumber->text();
    email = ui->customeremail->text();
    password = ui->customerpassword->text();

    for (int i = 0 ; i < this->supermarketobject.customers.size() ; i++)
    {
        if(this->supermarketobject.customers[i].getEmail() == email)
        {
            flag = true;
            QMessageBox::critical(this, "Sign Up" , "EMAIL Already Exists");
        }
        else if(email.isEmpty() || name.isEmpty() || password.isEmpty() || address.isEmpty() || password.isEmpty()) {
            flag=true;
            QMessageBox::critical(this, "Sign Up" , "Compelete Your Deatils");
            break;
        }
    }
    if(!flag)
    {
        QMessageBox::information(this , "Sign Up" , "Account Created succesfully");
        Customer temp (this->supermarketobject.generateId(),phonenumber,password,address,email,name);
        this->supermarketobject.customers.push_back(temp);
        supermarketobject.writeAllFiles();
        this->hide();
        loginmenu login;
        login.setModal(true);
        login.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
        login.exec();
    }
}

