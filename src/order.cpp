#include "order.hpp"

/* Normal Order Class */
Order::Order(int odrDate, int csmrNum, int quantity) {
    
        this->orderDate         = odrDate;
        this->customerNumber    = csmrNum;
        this->orderQuantity     = quantity;
}
Order::~Order(){}

/* Getters */
inline int Order::getOrderDate()       { return this->orderDate;       }
inline int Order::getCustomerNumber()  { return this->customerNumber;  }
inline int Order::getOrderQuantity()   { return this->orderQuantity;   }