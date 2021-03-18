#ifndef __ORDER_HPP
#define __ORDER_HPP

#include <string>
#include "customer.hpp"

/* 
 *  Order (odr) Prototype 
 */
class Order {
    
    protected:

        Customer *customer;
        int orderQuantity;
        char orderType;

    public:

        /* Constructor & Destructor */
        Order(Customer *, int, char);
        ~Order();   

        /* Getters */
        Customer *getCustomer();
        int getOrderQuantity(),
            getOrderDate();
        std::string getOrderType();

        /* Operator overload */
        friend std::ostream &operator <<(std::ostream &, Order &);
};

/* 
 *  Express Order (expr) Prototype 
 */
class Express : public Order {
    
    private:

        int orderDate;

    public:

        /* Constructor & Destructor */
        Express(Customer *, int, char, int);
        ~Express();   

        /* Getters */
        int getOrderDate();

};

#endif