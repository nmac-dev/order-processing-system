#include "order.hpp"

/* Normal Order Class */
inline Order::Order(int odrDate, int csmrNum, int quantity, char type) {
    
        this->orderDate         = odrDate;
        this->customerNumber    = csmrNum;
        this->orderQuantity     = quantity;
        this->orderType         = type;
}
inline Order::~Order(){}

/* Getters */
inline int  Order::getOrderDate()       { return this->orderDate;       }
inline int  Order::getCustomerNumber()  { return this->customerNumber;  }
inline int  Order::getOrderQuantity()   { return this->orderQuantity;   }

inline std::string Order::getOrderType() { 
        
        std::string type;

        if ( this->orderType == 'N')    { type = "normal";  }
        else                            { type = "EXPRESS"; }

        return "normal";        
}


/* returns the order details to the output stream */
inline std::ostream &operator <<(std::ostream &stream, Order &odr) {

        std::string customerDetails = "customer " 
                                    + std::to_string( odr.getCustomerNumber() ) 
                                    + ": ";

        std::string orderDetails    = odr.getOrderType() 
                                    + " order: quantity: " 
                                    + std::to_string( odr.getOrderQuantity() );
        
        stream << customerDetails << orderDetails;

        return stream;
}