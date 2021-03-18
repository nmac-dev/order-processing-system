#include "order.hpp"

/* 
 *      Normal Order Class 
 */
inline Order::Order(Customer *csmr, int quantity, char type) {
    
        this->customer          = csmr;
        this->orderQuantity     = quantity;
        this->orderType         = type;
}
inline Order::~Order(){}

/* Getters */
inline Customer *Order::getCustomer()      { return this->customer;      }
inline int       Order::getOrderDate()     { return 0;                   }
inline int       Order::getOrderQuantity() { return this->orderQuantity; }

inline std::string Order::getOrderType() { 
        
        std::string type;
        if ( this->orderType == 'N')    { type = "normal";  }
        else                            { type = "EXPRESS"; }

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

/* 
 *      Express Order Class 
 */
inline Express::Express(Customer *csmr, int quantity, char type, int odrDate) : 
                Order(csmr, quantity, type) {
        
        this->orderDate = odrDate;
}
inline Express::~Express(){}

/* Getters */
inline int Express::getOrderDate() { return this->orderDate; }