// Author: Fergus Haak
// replace application, allows for replacing #defined variable names in c files with their defined value.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BST.h"

using namespace std;

// Runs the main replace application
// Parameters:
// argv[1]: target c file for replacing
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        return 1; // Error Check: missing input file
    }
    ifstream file(argv[1]); // open file
    if (!file) {
        cerr << "Error opening file " << argv[1] << endl;
        return 1; // Error Check: file doesn't exist
    }

    BST tree; //Make a BST object
    vector<string> new_file_contents; //Make a String Vector object for storing output file data

    // rewrite opened file name to build the output file
    string new_file_name = argv[1];
    new_file_name = new_file_name.replace(new_file_name.size() - 2, 2, ".o");
    ofstream new_file(new_file_name); // replace ".c" with ".o"

    string line;
    while (getline(file, line)) {

        istringstream line_stream(line);
        string token;
        string new_line;
        bool was_define = false;

        while (line_stream >> token) {
            if (token == "#define") {
                was_define = true;
                // collect the next two tokens after #define token for defined name and value
                line_stream >> token;
                string name = token;
                line_stream >> token;
                string value = token;
                tree.insert_constant(name, value);

            }
            else
            {
                // if token exists as name in tree change the token to the value of said name
                string test = tree.get_value(token);
                if (test != ""){
                    new_line += tree.get_value(token) + " ";
                }
                else
                {
                    new_line += token + " ";
                }
            }
        }

        if (!was_define) // stops # define lines being added as blank onto the output
            new_file_contents.push_back(new_line);
    }
    for (string line: new_file_contents)
        new_file << line << endl;

    new_file.close();
    return 0;
}