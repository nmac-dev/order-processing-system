#ifndef __CUSTOMER_HPP
#define __CUSTOMER_HPP

#include <vector>
#include <iostream>
#include <iomanip>

#include "order.hpp"

/* Customer (csmr) Prototype */
class Customer {
    
    private:

        std::vector<Order *> orders;
        int     csmrID,
                totalOrders;
        std::string  csmrName;

    public:

        /* Constructor & Destructor */
        Customer(int, std::string);
        ~Customer();   

        /* Getters */
        int     getCsmrID(),
                getTotalOrders();
        std::string getCsmrName();

        /* Methods */
        void    addOrder(Order *),
                resetTotalOrders();
        friend std::ostream &operator <<(std::ostream &, Customer &);
};

#endif