#include "customer.hpp"

/* Customer (csmr) Class */
inline Customer::Customer(int id, std::string name) {
    
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
inline void Customer::addOrder(Order odr, int quantity) { 

        this->orders.push_back(odr);
        this->totalOrders += quantity;    
}

inline void Customer::resetTotalOrders() { this->totalOrders = 0; }

inline std::string Customer::toStringCsmrID() {

        std::string strCsmrID   = std::to_string(this->csmrID);
	std::string paddedID    = ""; 
	
	while(paddedID.length() != 4 - strCsmrID.length()) {

                paddedID += "0";
        }

        return paddedID + strCsmrID;
}