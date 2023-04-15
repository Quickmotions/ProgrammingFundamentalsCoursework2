#include <string>
#include "BST.h"
using namespace std;

string to_string_helper(Node *root);
void insert(Node *&root, const string& name, const string& value);
string search(Node *root, const string& search_name);


BST::BST()
{
    this->root = nullptr;
}

// Creates a binary search tree by copying all the constant value pairs
// from the existing binary search tree.
BST::BST(const BST &other)
{
    this->root = nullptr;
    //TODO: Implement the copy constructor
}

// Destructor for the BST class. frees all heap-allocated memory.
BST::~BST()
{
    //TODO: Implement the destructor
}

//A helper function to allow recursive calls
//You can add helper functions like this for the other methods,
//to recursively move through the tree
string to_string_helper(Node *root)
{
    if(root == nullptr)
    {
        return "";
    }
    else
    {
        return to_string_helper(root->left) + 
            root->name + "=" + root->value + " " +
            to_string_helper(root->right);
    }
}

void insert(Node *&root, const string& name, const string& value) {
    if (root == nullptr) {
        root = new Node;
        root->name = name;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (name < root->name) {
            insert(root->left, name, value);
        } else if (name > root->name) {
            insert(root->right, name, value);
        }
    }
}

string search(Node *root, const string& search_name){
    string output;
    if(root->name == search_name) {
        output = root->value;
    }
    if(output.empty() && root->left != nullptr){
        output = search(root->left, search_name);
    }
    if(output.empty() && root->right != nullptr){
        output = search(root->right, search_name);
    }
    return output;
}

int count_nodes(Node *root){
    int count = 0;
    if (root != nullptr){
        count++;
    }
    if (root->left != nullptr){
        count += count_nodes(root->left);
    }
    if (root->right != nullptr){
        count += count_nodes(root->right);
    }
    return count;
}

string BST::to_string() const
{
    string ret = to_string_helper(this->root);
    if(ret.length() > 1)
    {
         ret.pop_back(); //remove final space
    }
    return ret;
}


// Inserts the constant (name) and its corresponding value
// (value) into the correct position in the tree.
void BST::insert_constant(string name, string value)
{
    insert(*&this->root, name, value);
}

// Returns the value that corresponds to (name),
// Returns "" if name does not exist.
string BST::get_value(string name) const
 {
    return search(*&this->root, name);
 }


// Returns number of constant value pairs
int BST::num_constants() const
{
    return count_nodes(*&this->root);
}

// Deletes the trees in tree1
BST& BST::operator=(const BST &rhs)
{
    
	return *this; //TODO: Add code here to implement the = operator
}
