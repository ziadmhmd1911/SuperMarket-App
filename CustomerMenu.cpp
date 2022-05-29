#include "CustomerMenu.h"
#include "ratingsystem.h"
#include "recipet.h"
#include "ui_customermenu.h"
#include "Buy.h"
#include "Search.h"
CustomerMenu::CustomerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerMenu)
{
    ui->setupUi(this);
    QPixmap bkgnd("D:/qt/bkgnd2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

CustomerMenu::~CustomerMenu()
{
    delete ui;
}

void CustomerMenu::on_buy_clicked()
{
    this->hide();
    Buy buy;
    buy.setModal(true);
    buy.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    buy.exec();
}


void CustomerMenu::on_search_clicked()
{
    this->hide();
    Search search;
    search.setModal(true);
    search.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    search.exec();
}


void CustomerMenu::on_view_clicked()
{
    this->hide();
    Recipet recipet;
    recipet.setModal(true);
    recipet.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    recipet.exec();
}


void CustomerMenu::on_Rating_clicked()
{
    this->hide();
    RatingSystem rate;
    rate.setModal(true);
    rate.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    rate.exec();
}

