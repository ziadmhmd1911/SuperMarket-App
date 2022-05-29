#ifndef SELLERMENU_H
#define SELLERMENU_H

#include <QDialog>
#include "SuperMarket.h"
namespace Ui {
class SellerMenu;
}

class SellerMenu : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit SellerMenu(QWidget *parent = nullptr);
    ~SellerMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SellerMenu *ui;
};
#endif // SELLERMENU_H
