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
int         shipOrders(Customer *);
void        sendInvoice(Customer *, int, int);

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
                    
                    sendInvoice( 
                        currentCsmr,
                        newOrder->getOrderDate(),
                        shipOrders( currentCsmr )
                    );
                }
                break;

            // Invoke End-Of-Day
            case 'E':
                /* Messages TODO~
                    end of day 20200201:
                        quantity of X shipped to customer Y; customer Y order quantity reset to 0
                 */
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
    if ( type == 'N') {

        newOrder = new Order(customer, quantity, type);
    }
    else if ( type == 'X') {
        
        newOrder = new Express(customer, quantity, type, odrDate);
    }
    else {

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

    // Add order to customer orders
    customer->addOrder( newOrder, newOrder->getOrderQuantity() );
    
    // Send Message to output stream
    cout << "OP: "
         << *newOrder
         << endl;

    return newOrder;
}

/* Delete and Clear all orders for the customer, then output the shipped total */
int shipOrders( Customer *csmr ) {

    int totalQuantity = csmr->getTotalQuantity();
    Order *ptr = NULL;

    // Delete all orders
    for ( Order *odr : csmr->getOrders() ) {
        ptr = odr;
        cout << "Deleted: " << odr->getOrderQuantity() << endl;
        delete odr;
        cout << "Post Del: " << ptr->getOrderQuantity() << endl;
    }
    // Clear vector and reset customer total quantity
    csmr->getOrders().clear();
    csmr->resetTotalQuantity();

    // OP: customer 0001: shipped quantity 240
    cout << "OP: customer "
         << *csmr
         << ": shipped quantity "
         << totalQuantity
         << endl;

    return totalQuantity;
}

void sendInvoice(Customer *customer, int date, int totalQuantity) {

    static int invoiceNum = invoiceNum++;

    // SC: customer 0002:  invoice 1002:  date 20200202:  quantity:  220
    cout << "SC: customer "
         << *customer
         << ": invoice "
         << invoiceNum
         << ": date "
         << date
         << ": quantity: "
         << totalQuantity
         << endl;

}