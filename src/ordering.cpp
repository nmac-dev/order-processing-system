#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

/* Prototypes */
vector<string>  &loadInputFileData(         const char *        );
void            runOrderProcessingSystem(   vector<string> &    );


int main(int argc, char **argv) {

    /* validate CL arguments size */
    if (argc != 2) {
        cerr << "Error: command line expects [Input File] directory argument..." << endl;
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

    /* Iterate through vector index for each data entry */
    for (int i = 0; i < inputData.size(); i++) {
        
        char firstChar = inputData[i][0];
        switch (firstChar) {
            
            /* Customer */
            case 'C':
                // ...
                break;

            /* Order */
            case 'S':
                // ...
                break;

            /* End-Of-Day */
            case 'E':
                // ...
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

