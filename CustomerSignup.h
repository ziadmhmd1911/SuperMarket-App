#ifndef CUSTOMERSIGNUP_H
#define CUSTOMERSIGNUP_H
#include "SuperMarket.h"
#include <QDialog>

namespace Ui {
class CustomerSignUp;
}

class CustomerSignUp : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit CustomerSignUp(QWidget *parent = nullptr);
    ~CustomerSignUp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CustomerSignUp *ui;
};
#endif // CUSTOMERSIGNUP_H
