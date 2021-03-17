

#include <cctype>
#include <fstream>

#include "order.cpp"
#include "customer.cpp"

using namespace std;

/* Prototypes */
vector<string>  &loadInputFileData(const char *);
void        runOrderProcessingSystem(vector<string> &);
Customer    processCustomer(string, vector<Customer> &);
void        processOrder(string, vector<Customer> &);

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

    vector<Customer> customers;

    /* Iterate through each data entry stored in the vector */
    for (int i = 0; i < inputData.size(); i++) {
        
        char firstChar = inputData[i][0];
        switch (firstChar) {
            
            /* Customer */
            case 'C':
                processCustomer( inputData[i], customers );
                /* Messages TODO~
                    new customer added, with customer number X and current order quantity 0
                 */
                break;

            /* Order */
            case 'S':
            processOrder( inputData[i], customers );
                /* Messages TODO~
                    customer X:  order quantity is incremented by Y
                 */
                break;

            /* End-Of-Day */
            case 'E':
                /* Messages TODO~
                    end of day 20200201:
                        quantity of X shipped to customer Y; customer Y order quantity reset to 0
                 */
                break;

            /* Error: file format for*/
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
        cout << firstChar << endl; // DEBUG
    }
}

/* Processes and validates a new customer to be added from the input data */
Customer processCustomer(string inputLine, vector<Customer> &currentCustomers) {

    int number  = stoi( inputLine.substr(1, 4) );
    string name = inputLine.substr(5, 44);

    Customer newCustomer = Customer(number, name);

    // Validate customer is not duplicate
    for( int j = 0; j < currentCustomers.size(); j++ ) {

        if ( number == currentCustomers[j].getCsmrID() ) {

            cerr << "Error: Duplicate customer found within input file... "
                 << "\nID: \t"
                 << newCustomer.toStringCsmrID()
                 << "\nName: \t"
                 << newCustomer.getCsmrName()
                 << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Send Message to output stream
    cout << "OP: customer "
         << newCustomer.toStringCsmrID()
         << " added"
         << endl;

    return newCustomer;
}

/* Processes and validates a new order to be added from the input data */
void processOrder(string inputLine, vector<Customer> &currentCustomers) {

    // TODO: CUSTOMER IS NULL

    int  odrDate    = stoi( inputLine.substr(1, 8) );
    char orderType  = inputLine[9];
    int  csmrNum    = stoi( inputLine.substr(10, 4) );
    int  quantity   = stoi( inputLine.substr(14, 3) );

    cout     << "\n |Date: " 
             << odrDate
             << "\n |Order Type: "
             << orderType
             << "\n |Customer Number: "
             << csmrNum
             << "\n |Quantity: "
             << quantity
             << endl;

    Order newOrder = Order(0, 0, 0);

    // Validate order type
    if ( orderType == 'N') {

        newOrder = Order(odrDate, csmrNum, quantity);
    }
    else if ( orderType == 'X') {

        newOrder = Order(odrDate, csmrNum, quantity);
        cout << "Create EXPR ORder" <<endl;
    }
    else {

        cerr << "Error: order either; has no type defined ('N'/'X') or follows an incorrect format"
             << "\n |Date: " 
             << odrDate
             << "\n |Order Type: "
             << orderType
             << "\n |Customer Number: "
             << csmrNum
             << "\n |Quantity: "
             << quantity
             << endl;
        exit(EXIT_FAILURE);
    }

    // Add order to customer orders
    int i = 0;
    do {

        cout << "OdrNum: " << newOrder.getCustomerNumber()
             << "CsmrID: " << currentCustomers[i].getCsmrID()
             << endl;
        if ( newOrder.getCustomerNumber() == currentCustomers[i].getCsmrID()) {

            currentCustomers[i].addOrder( newOrder );
            break;
        }
        i++;
    } 
    while (i < currentCustomers.size());
    
    // OP: customer 0001:  normal order:  quantity 40
        // << currentCustomers[i].toStringCsmrID()
    cout << "OP: customer "
         << ": "
         << newOrder.toStringOrderType()
         << " order: "
         << "quantity 40"
         << endl;
}