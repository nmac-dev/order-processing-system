#ifndef __ORDERING_HPP
#define __ORDERING_HPP

#include <cctype>
#include <fstream>
#include "customer.cpp"
#include "order.cpp"

std::vector<std::string> &loadInputFileData(const char *);
void        runOrderProcessingSystem(std::vector<std::string> &);
Customer   *processCustomer(std::string, std::vector<Customer *> &);
Order      *processOrder( std::string, std::vector<Customer *> &);
void        finaliseOrders(Customer *, int *, int);
void        processEndOfDay(std::string, std::vector<Customer *> &, int *);

#endif