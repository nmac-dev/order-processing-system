#include "order.hpp"

/* Normal Order Class */
inline Order::Order(int odrDate, int csmrNum, int quantity) {
    
        this->orderDate         = odrDate;
        this->customerNumber    = csmrNum;
        this->orderQuantity     = quantity;
}
inline Order::~Order(){}

/* Getters */
inline int  Order::getOrderDate()       { return this->orderDate;       }
inline int  Order::getCustomerNumber()  { return this->customerNumber;  }
inline int  Order::getOrderQuantity()   { return this->orderQuantity;   }
inline std::string Order::toStringOrderType() { return "normal";        }

/* returns the order details as a string */
inline std::string Order::toStringOrderDetails(int csmrNum) {  
    
    // customer 0001:  normal order:  quantity 40
    std::string orderDetails =   "customer " 
                                + std::to_string( csmrNum ); 
                                + ": "
                                + this->toStringOrderType() 
                                + " order: "
                                + "quantity: " 
                                + std::to_string( this->orderQuantity );

    return orderDetails;

}