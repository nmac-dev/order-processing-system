#include "order.hpp"

/* 
 *      Order (odr) Class 
 */
inline Order::Order(int date, char type, Customer *csmr, int quantity) {
    
        this->orderDate     = date;
        this->orderType     = type;
        this->customer      = csmr;
        this->orderQuantity = quantity;
}
inline Order::~Order(){}

/* Getters */
inline Customer *Order::getCustomer()      { return this->customer;      }
inline int       Order::getOrderDate()     { return this->orderDate;     }
inline int       Order::getOrderQuantity() { return this->orderQuantity; }

/* Translate the order type to a string */
inline std::string Order::getOrderType() { 
        
        std::string type;
        if ( this->orderType == 'N') { type = "normal";  }
        else                         { type = "EXPRESS"; }

        return type;        
}

/* returns the order details to the output stream */
inline std::ostream &operator <<(std::ostream &stream, Order &odr) {
        
        stream  << "customer " 
                << *odr.getCustomer() 
                << ": " 
                << odr.getOrderType() 
                << " order: quantity: " 
                << std::to_string( odr.getOrderQuantity() );

        return stream;
}