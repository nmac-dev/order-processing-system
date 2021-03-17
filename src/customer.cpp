#include "customer.hpp"

/* Customer (csmr) Class */
inline Customer::Customer(int id, std::string name) {
    
        
        std::vector<Order> orders;
        this->csmrID        = id;
        this->csmrName      = name;
        this->totalOrders   = 0;
}
inline Customer::~Customer(){}

/* Getters */
inline int             Customer::getCsmrID()       { return this->csmrID;        }
inline int             Customer::getTotalOrders()  { return this->totalOrders;   }
inline std::string     Customer::getCsmrName()     { return this->csmrName;      }

/* Methods */
inline void Customer::addOrder(Order *odr) { 

        this->orders.push_back(odr);
        this->totalOrders += odr->getOrderQuantity();    
}

inline void Customer::resetTotalOrders() { this->totalOrders = 0; }

/* Returns the padded customer id */
inline std::ostream &operator <<(std::ostream &stream, Customer &csmr) {

        stream << std::setfill('0') << std::setw(4) << csmr.getCsmrID();
        return stream;
}