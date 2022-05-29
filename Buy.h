#ifndef BUY_H
#define BUY_H

#include <QDialog>
#include "SuperMarket.h"
namespace Ui {
class Buy;
}

class Buy : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit Buy(QWidget *parent = nullptr);
    ~Buy();

private slots:

    void on_view_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Buy *ui;
};

#endif // BUY_H
