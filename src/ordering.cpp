#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    /* validate CL arguments size */
    if (argc != 2) {
        cerr << "Error: command line expects [Input File] directory argument..." << endl;
        exit(EXIT_FAILURE);
    }

    char *fileIn = argv[1];

    exit(EXIT_SUCCESS);
}