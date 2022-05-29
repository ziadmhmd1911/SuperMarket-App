#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SellerSignup.h"
#include <iostream>
#include "SuperMarket.h"
#include "Seller.h"
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QTextEdit>
#include <vector>
#include "CustomerSignup.h"
#include "LoginMenu.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("D:/qt/bkgnd2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    QPixmap pix("D:/qt/facebook.png");
    ui->pic_label->setPixmap(pix);
    QPixmap pix2("D:/qt/instagram.png");
    ui->pic_label_2->setPixmap(pix2);
    QPixmap pix3("D:/qt/github.png");
    ui->pic_label_3->setPixmap(pix3);
    QPixmap pix4("D:/qt/linkedin.png");
    ui->pic_label_4->setPixmap(pix4);
    QPixmap pix5("D:/qt/whatsapp.png");
    ui->pic_label_5->setPixmap(pix5);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    this->hide();
    sellerSignUp sellersignup;
    sellersignup.setModal(true);
    sellersignup.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    sellersignup.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    CustomerSignUp customersignup;
    customersignup.setModal(true);
    customersignup.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    customersignup.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->hide();
    loginmenu login;
    login.setModal(true);
    login.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    login.exec();
}

