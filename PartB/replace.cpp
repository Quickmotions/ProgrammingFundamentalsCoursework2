#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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
    BST tree;
    vector<string> new_file_contents;

    string new_file_name = argv[1];
    new_file_name = new_file_name.replace(new_file_name.size() - 2, 2, ".o");
    ofstream new_file(new_file_name); // replace ".c" with ".o");

    string line;
    while (getline(file, line)) { // for line in file

        istringstream line_stream(line);
        string token;
        string new_line;
        bool was_define = false;

        while (line_stream >> token) { // for token in line
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
        if (!was_define)
            new_file_contents.push_back(new_line);
    }
    for (string line: new_file_contents)
        new_file << line << endl;
    new_file.close();
    return 0;
}