#include "customer.hpp"

/* Customer (csmr) Class */
inline Customer::Customer(int id, std::string name) {
    
        this->csmrID    = id;
        this->csmrName  = name;
        this->totalQuantity = 0;
        std::vector<Order *> orders;
}
inline Customer::~Customer(){}

/* Getters */
inline int             Customer::getCsmrID()        { return this->csmrID;        }
inline int             Customer::getTotalQuantity() { return this->totalQuantity; }
inline std::string     Customer::getCsmrName()      { return this->csmrName;      }
inline std::vector<Order *> &Customer::getOrders()  { return this->orders;       }

/* Methods */
inline void Customer::addOrder(Order *odr, int quantity) { 

        this->orders.push_back(odr);
        this->totalQuantity += quantity;    
}

inline void Customer::resetTotalQuantity() { this->totalQuantity = 0; }

/* Returns the padded customer id */
inline std::ostream &operator <<(std::ostream &stream, Customer &csmr) {

        stream  << std::setfill('0') 
                << std::setw(4) 
                << csmr.getCsmrID();
        return stream;
}