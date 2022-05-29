#ifndef SELLERSIGNUP_H
#define SELLERSIGNUP_H

#include <QDialog>
#include "SuperMarket.h"
namespace Ui {
class sellerSignUp;
}

class sellerSignUp : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit sellerSignUp(QWidget *parent = nullptr);
    ~sellerSignUp();


private slots:
    void on_pushButton_clicked();

private:
    Ui::sellerSignUp *ui;
};
#endif // SELLERSIGNUP_H
