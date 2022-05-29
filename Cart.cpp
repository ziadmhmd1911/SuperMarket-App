//
// Created by Ziad on 4/24/2022.
//

#include "Cart.h"
#include <iostream>
#include "CustomerMenu.h"
#include "QString"
using namespace std;

QString Cart::calculate_total_price()
{
    float total = 0;
    for(int i = 0 ; i < this->cart_items.size() ; i++)
    {
        bool ok;
        double x = cart_items[i].getPrice().toInt(&ok);
        int y = cart_items[i].getQuantity().toInt(&ok);
        total += x*y;
    }
    QString xx = QString::number(total);
    return xx;
}
