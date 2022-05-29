#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include <QDialog>

namespace Ui {
class CustomerMenu;
}

class CustomerMenu : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerMenu(QWidget *parent = nullptr);
    ~CustomerMenu();

private slots:
    void on_buy_clicked();

    void on_search_clicked();

    void on_view_clicked();

    void on_Rating_clicked();

private:
    Ui::CustomerMenu *ui;
};
#endif // CUSTOMERMENU_H
