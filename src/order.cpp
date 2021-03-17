#ifndef __ORDER_HPP

#include "order.hpp"

#endif
/* Normal Order Class */
Order::Order(int odrDate, int csmrNum, int quantity) {
    
        this->orderDate         = odrDate;
        this->customerNumber    = csmrNum;
        this->orderQuantity     = quantity;
}
Order::~Order(){};

/* Getters */
int Order::getOrderDate()       { return this->orderDate;       }
int Order::getCustomerNumber()  { return this->customerNumber;  }
int Order::getOrderQuantity()   { return this->orderQuantity;   }