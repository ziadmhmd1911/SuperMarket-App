#include "SellerSignup.h"
#include "LoginMenu.h"
#include "ui_SellerSignup.h"
#include "Seller.h"
#include <QMessageBox>
sellerSignUp::sellerSignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sellerSignUp)
{
    ui->setupUi(this);
    QPixmap bkgnd("D:/qt/login.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

sellerSignUp::~sellerSignUp()
{
    delete ui;
}

void sellerSignUp::on_pushButton_clicked()
{
    QString name;
    QString email;
    QString password;
    bool flag = false;
     name = ui->sellername->text();
     email = ui->selleremail->text();
     password = ui->sellerpassword->text();

     if(supermarketobject.customers.empty())
     {
        supermarketobject.readAllFiles();
     }
     for (int i = 0 ; i < this->supermarketobject.sellers.size() ; i++)
    {
        if(this->supermarketobject.sellers[i].getEmail() == email)
        {
            flag = true;
            QMessageBox::critical(this , "SIGN UP" , "EMAIL ALREADY EXISTS");
        }
        else if (email.isEmpty() || name.isEmpty() || password.isEmpty()){
            flag=true;
            QMessageBox::critical(this , "SIGN UP" , "Please Fill All Data");
        }

    }

    if (!flag)
    {
        Seller temp (this->supermarketobject.generateId(),name,email,password,0,0,0);
        this->supermarketobject.sellers.push_back(temp);
        this->supermarketobject.writeToFileFromSeller();
        QMessageBox::information(this , "SIGN UP" , "SUCCESS");
        this->hide();
        loginmenu login;
        login.setModal(true);
        login.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
        login.exec();
    }
}

