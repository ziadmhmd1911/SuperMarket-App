#ifndef LOGINMENU_H
#define LOGINMENU_H

#include <QDialog>
#include "SuperMarket.h"
#include "CustomerMenu.h"
namespace Ui {
class loginmenu;
}

class loginmenu : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit loginmenu(QWidget *parent = nullptr);
    ~loginmenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginmenu *ui;
    CustomerMenu customermenu;
};
#endif // LOGINMENU_H
