#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "SuperMarket.h"
namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT
    SuperMarket supermarketobject;
public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Search *ui;
};
#endif // SEARCH_H
