#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

/* Prototypes */


int main(int argc, char **argv) {

    /* validate CL arguments size */
    if (argc != 2) {
        cerr << "Error: command line expects [Input File] directory argument..." << endl;
        exit(EXIT_FAILURE);
    }
    const char *fileIn = argv[1];


    /* Load Input File Contents */
    vector<string> inputData;
    
    ifstream inputFile;
    try {

        inputFile.open(fileIn);
        if ( inputFile.is_open() ) {

            string line;
            while( getline(inputFile, line) ) {
                inputData.push_back(line);
                cout << line << endl;       // Debug
            } 

        } else throw( fileIn );
        inputFile.close();
    } 
    catch ( const char *e )  {
        cerr << "Error: could not open/read input file... " << e << endl;
        exit(EXIT_FAILURE);
    }

    /* Program Complete */
    exit(EXIT_SUCCESS);
}



/* Process Input File Data */



/* Customer Class */
class Customer {
    
    // csmr == customer
    private:

        int csmrID;
        string csmrName;
        int csmrCurrentOrders;

        /* Setter */
        void setCsmrID(int id)          { csmrID = id;      }
        void setCsmrName(string name)   { csmrName = name;  }

    public:

        /* Getters */
        int getCsmrID()         { return csmrID;    }
        string getCsmrName()    { return csmrName;  }
        

    Customer(int id, string name) {
        setCsmrID(id);
        setCsmrName(name);
    }
        
};

