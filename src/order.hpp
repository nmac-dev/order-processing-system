#ifndef __ORDER_HPP
#define __ORDER_HPP

#include <string>

/* Customer (csmr) Prototype */
class Order {
    
    protected:

        int  orderDate,
             customerNumber,
             orderQuantity;
        char orderType;

    public:

        /* Constructor & Destructor */
        Order(int, int, int, char);
        ~Order();   

        /* Getters */
        int     getOrderDate(),
                getCustomerNumber(),
                getOrderQuantity();
        std::string getOrderType(),
                    toStringOrderDetails(int);
        friend std::ostream &operator <<(std::ostream &, Order &);
};

#endif