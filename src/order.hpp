#ifndef __ORDER_HPP
#define __ORDER_HPP

#include <string>

/* Customer (csmr) Prototype */
class Order {
    
    protected:

        int     orderDate,
                customerNumber,
                orderQuantity;

    public:

        /* Constructor & Destructor */
        Order(int, int, int);
        ~Order();   

        /* Getters */
        int     getOrderDate(),
                getCustomerNumber(),
                getOrderQuantity();
        std::string strOrderType(),
                    strOrderDetails(int);
};

#endif