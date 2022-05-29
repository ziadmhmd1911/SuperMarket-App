#ifndef SELLEREDIT_H
#define SELLEREDIT_H

#include "SuperMarket.h"
#include <QDialog>

namespace Ui {
class SellerEdit;
}

class SellerEdit : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit SellerEdit(QWidget *parent = nullptr);
    ~SellerEdit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SellerEdit *ui;
};

#endif // SELLEREDIT_H
