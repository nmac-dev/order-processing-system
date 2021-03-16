#ifndef __CUSTOMER_HPP
#define __CUSTOMER_HPP

#include <string>

using namespace std;

#endif

/* Customer (csmr) Prototype */
class Customer {
    
    protected:

        int     csmrID,
                totalOrders;
        string  csmrName;

    public:

        /* Constructor & Destructor */
        Customer(int, string);
        ~Customer();   

        /* Getters */
        int     getCsmrID(),
                getTotalOrders();
        string  getCsmrName();

        /* Methods */
        void    addOrderQuantity(int),
                resetTotalOrders();
};