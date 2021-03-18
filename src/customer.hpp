#ifndef __CUSTOMER_HPP
#define __CUSTOMER_HPP

#include <vector>
#include <iostream>
#include <iomanip>

// Order class forward decleration
class Order;

/* 
 * Customer (csmr) Prototype 
 */
class Customer {
    
    private:

        int     csmrID,
                totalQuantity;
        std::string  csmrName;
        std::vector<Order *> orders;

    public:

        /* Constructor & Destructor */
        Customer(int, std::string);
        ~Customer();   

        /* Getters */
        int     getCsmrID(),
                getTotalQuantity();
        std::string getCsmrName();
        std::vector<Order *> &getOrders();

        /* Methods */
        void    addOrder(Order *, int),
                resetTotalQuantity();
        friend std::ostream &operator <<(std::ostream &, Customer &);
};

#endif