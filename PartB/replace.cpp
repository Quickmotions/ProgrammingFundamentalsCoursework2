#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"

using namespace std;

int main(int argc, char* argv[]) {

    // missing input file
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        return 1;
    }

    // file doesn't exist
    ifstream file(argv[1]);
    if (!file) {
        cerr << "Error opening file " << argv[1] << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        istringstream line_stream(line);
        string token;

        while (line_stream >> token) {
            if (token == "#define") {
                cout << "Found #define token!" << endl;
            }
        }
    }

    return 0;
}