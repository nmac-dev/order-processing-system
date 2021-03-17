#ifndef __CUSTOMER_HPP

#include "customer.hpp"

#endif

/* Customer (csmr) Class */
Customer::Customer(int id, std::string name) {
    
        this->csmrID        = id;
        this->csmrName      = name;
        this->totalOrders   = 0;
}
Customer::~Customer(){};

/* Getters */
int             Customer::getCsmrID()       { return this->csmrID;        }
int             Customer::getTotalOrders()  { return this->totalOrders;   }
std::string     Customer::getCsmrName()     { return this->csmrName;      }

/* Methods */
void Customer::addOrder(Order odr, int quantity) { 

        this->orders.push_back(odr);
        this->totalOrders += quantity;    
}

void Customer::resetTotalOrders() { this->totalOrders = 0; }