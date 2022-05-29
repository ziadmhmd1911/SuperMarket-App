//
// Created by Ziad on 4/24/2022.
//

#ifndef DATASTRUCTURE_CART_H
#define DATASTRUCTURE_CART_H
#include <string>
#include "Product.h"
#include <vector>
#include "QString"
using namespace std ;

class Cart {
public:
    vector<Product> cart_items;

    QString calculate_total_price();
};
#endif //DATASTRUCTURE_CART_H
