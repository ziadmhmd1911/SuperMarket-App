#ifndef RECIPET_H
#define RECIPET_H

#include "SuperMarket.h"
#include <QDialog>
#include <QTimer>
namespace Ui {
class Recipet;
}

class Recipet : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit Recipet(QWidget *parent = nullptr);
    ~Recipet();
public slots:
    void myfunction();
private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Recipet *ui;
    QTimer *timer;
};
#endif // RECIPET_H
