#include <cctype>
#include <fstream>

#include "customer.cpp"
#include "order.cpp"

using namespace std;

/* Prototypes */
vector<string>  &loadInputFileData(const char *);
void        runOrderProcessingSystem(vector<string> &);
Customer   *processCustomer(string, vector<Customer *> &);
Order      *processOrder(   string, vector<Customer *> &);
void        finaliseOrders( Customer *, int, int);
void        processEndOfDay(string, vector<Customer *> &, int);

int main(int argc, char **argv) {

    /* validate CL arguments size */
    if (argc != 2) {
        cerr << "Error: command line expects a single [ InputFile.txt ] directory argument..." << endl;
        exit(EXIT_FAILURE);
    }
    const char *fileIn = argv[1];


    /* Load Input File Contents */
    vector<string> &inputData = loadInputFileData(fileIn);

    /* Run Order Processing System */
    runOrderProcessingSystem(inputData);

    /* Program Complete */
    exit(EXIT_SUCCESS);
}

/* Process Input File Data */
vector<string> &loadInputFileData(const char *fileIn) {
    
    static vector<string> inputData;
    ifstream inputFile;
    try {

        inputFile.open(fileIn);
        if ( inputFile.is_open() ) {

            string line;
            while( getline(inputFile, line) ) {
                inputData.push_back(line);
            } 

        } else throw( fileIn );
        inputFile.close();
    } 
    catch ( const char *e )  {
        cerr << "Error: could not open/read input file... " << e << endl;
        exit(EXIT_FAILURE);
    }
    return inputData;
}

void runOrderProcessingSystem(vector<string> &inputData) {

    static vector<Customer *> customers;
    Customer *currentCsmr;
    Order    *newOrder;
    int invoiceDate;
    int invoiceNumber = 0;

    /* Iterate through each data entry stored in the vector */
    for (int i = 0; i < inputData.size(); i++) {

        char firstChar = inputData[i][0];
        switch (firstChar) {
            
            // Add Customer
            case 'C':

                customers.push_back( processCustomer(inputData[i], customers) );
                break;

            // Add Order
            case 'S':

                newOrder = processOrder(inputData[i], customers);
                // Ship an invoice if the order is an express
                if ( newOrder->getOrderType() == "EXPRESS" ) {
                    
                    currentCsmr = newOrder->getCustomer();
                    invoiceDate = newOrder->getOrderDate();

                    invoiceNumber++;
                    finaliseOrders( currentCsmr, invoiceNumber, invoiceDate );
                }
                break;

            // Invoke End-Of-Day
            case 'E':
                invoiceNumber++;
                processEndOfDay( inputData[i], customers, invoiceNumber);
                break;

            /* Error: file format incorrect */
            default:
                // False positive Error (skip)
                if( isspace(firstChar) || firstChar == 0) {

                    continue;
                }
                // True Error
                else {

                    cerr    << "Error: Input file contains invalid format, the first character must be 'C' 'S' or 'E' but.. " 
                            << firstChar 
                            << " ..on line.. "
                            << ++i
                            << " ..was found!"
                            << endl;
                    exit(EXIT_FAILURE);
                }
        }
    }
}

/* Processes and validates a new customer to be added from the input data */
Customer *processCustomer(string inputLine, vector<Customer *> &currentCustomers) {

    int number  = stoi( inputLine.substr(1, 4) );
    string name = inputLine.substr(5, 39);

    Customer *newCustomer = new Customer(number, name);

    // Validate customer is not duplicate
    for( Customer *csmr : currentCustomers ) {

        if ( number == csmr->getCsmrID() ) {

            cerr << "Error: Duplicate customer found within input file... "
                 << "\nID: \t"
                 << *newCustomer
                 << "\nName: \t"
                 << newCustomer->getCsmrName()
                 << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Send Message to output stream
    cout << "OP: customer "
         << *newCustomer
         << " added"
         << endl;

    return newCustomer;
}

/* Processes and validates a new order to be added from the input data */
Order *processOrder(string inputLine, vector<Customer *> &currentCustomers) {


    int  odrDate    = stoi( inputLine.substr(1, 8) );
    char type       = inputLine[9];
    int  csmrNum    = stoi( inputLine.substr(10, 4) );
    int  quantity   = stoi( inputLine.substr(14, 3) );

    Customer *customer = NULL;
    Order    *newOrder = NULL;

    // Add order to customer orders
    for (Customer *csmr : currentCustomers) {

        if ( csmrNum == csmr->getCsmrID()) {

            customer = csmr;
            break;
        }
    }
        
    // Validate order type
    if ( type != 'N' && type != 'X') {

        cerr << "Error: order either; has no type defined ('N'/'X') or follows an incorrect format"
             << "\n |Date: " 
             << odrDate
             << "\n |Order Type: "
             << type
             << "\n |Customer Number: "
             << csmrNum
             << "\n |Quantity: "
             << quantity
             << endl;
        exit(EXIT_FAILURE);
    }

    newOrder = new Order(odrDate, type, customer, quantity);
    customer->addOrder( newOrder, newOrder->getOrderQuantity() );
    
    // Send Message to output stream
    cout << "OP: "
         << *newOrder
         << endl;

    return newOrder;
}

/* Delete and Clear all orders for the customer, then output the shipped total and invoke an invoice */
void finaliseOrders( Customer *csmr, int invoiceNum, int date) {

    int totalQuantity = csmr->getTotalQuantity();

    // Delete and Clear all orders
    for ( Order *odr : csmr->getOrders() ) {
        
        delete odr;
    }
    csmr->getOrders().clear();
    csmr->resetTotalQuantity();

    // Output Shipped Orders
    cout << "OP: customer "
         << *csmr
         << ": shipped quantity "
         << totalQuantity
         << endl;

    // Output Invoice
    cout << "SC: customer "
         << *csmr
         << ": invoice "
         << setfill('0') 
         << std::setw(4) 
         << invoiceNum
         << ": date "
         << date
         << ": quantity: "
         << totalQuantity
         << endl;
}

/* Output notification for the end of the day, then ship orders and send an invoice ( only if orders are > 0 )*/
void processEndOfDay(string inputLine, vector<Customer *> &customers, int invoiceNum) {

    int invoiceDate = stoi( inputLine.substr(1, 8) );
    
    cout << "OP: end of day "
         << invoiceDate
         << endl;

    for (Customer *csmr : customers) {
        
        if ( csmr->getTotalQuantity() > 0 ) {
            
            finaliseOrders( csmr, invoiceNum, invoiceDate );
        }
    }
}