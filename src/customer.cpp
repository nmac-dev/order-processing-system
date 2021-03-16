#include "customer.hpp"

/* Customer (csmr) Class */
Customer::Customer(int id, string name) {
    
        this->csmrID        = id;
        this->csmrName      = name;
        this->totalOrders   = 0;
}
Customer::~Customer(){};

/* Getters */
int     Customer::getCsmrID()       { return this->csmrID;        }
int     Customer::getTotalOrders()  { return this->totalOrders;   }
string  Customer::getCsmrName()     { return this->csmrName;      }

/* Methods */
void    Customer::addOrderQuantity(int quantity)    { this->totalOrders += quantity;    }
void    Customer::resetTotalOrders()                { this->totalOrders = 0;            }