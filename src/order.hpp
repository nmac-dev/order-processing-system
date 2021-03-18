#ifndef __ORDER_HPP
#define __ORDER_HPP

#include <string>
#include "customer.hpp"

/* 
 *  Order (odr) Prototype 
 */
class Order {
    
    protected:

        char orderType;
        int orderDate,
            orderQuantity;
        Customer *customer;

    public:

        /* Constructor & Destructor */
        Order(int, char, Customer *, int);
        ~Order();   

        /* Getters */
        Customer *getCustomer();
        int getOrderQuantity(),
            getOrderDate();
        std::string getOrderType();

        /* Operator Overload */
        friend std::ostream &operator <<(std::ostream &, Order &);
};

#endif