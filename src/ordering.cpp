#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

    /* validate CL arguments size */
    if (argc != 2) {
        cerr << "Error: command line expects [Input File] directory argument..." << endl;
        exit(EXIT_FAILURE);
    }

    char *fileIn = argv[1];

    /* Load input file */
    ifstream inputFile;
    try {

        inputFile.open(fileIn);
        if ( inputFile.is_open() ) {

            string line;
            while( getline(inputFile, line) ) {
                cout << line << endl;
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
