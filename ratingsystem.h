#ifndef RATINGSYSTEM_H
#define RATINGSYSTEM_H

#include "SuperMarket.h"
#include <QDialog>

namespace Ui {
class RatingSystem;
}

class RatingSystem : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;

public:
    explicit RatingSystem(QWidget *parent = nullptr);
    ~RatingSystem();

private slots:

    void on_subproductrate_clicked();

    void on_subsellerrate_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RatingSystem *ui;
};

#endif // RATINGSYSTEM_H
