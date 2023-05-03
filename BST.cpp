// Author: Fergus Haak
// BST main file, binary search tree related methods

#include <string>
#include "BST.h"
using namespace std;

string to_string_helper(Node *root);
void insert_helper(Node *&root, const string& name, const string& value);
string search_helper(Node *root, const string& search_name);
Node* copy_helper(Node *node);
void destructor_helper(Node *root);

// BST To String Helper Method used only by to_string method.
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

// BST Insert Helper Method used only by insert method.
void insert_helper(Node *&root, const string& name, const string& value) {
    if (root == nullptr) {
        root = new Node;
        root->name = name;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (name < root->name) {
            insert_helper(root->left, name, value);
        } else if (name > root->name) {
            insert_helper(root->right, name, value);
        }
    }
}

// BST Get Helper Method used only by get method.
string search_helper(Node *root, const string& search_name){
    string output;
    if (root == nullptr) {
        return "";
    }
    if(root->name == search_name) {
        output = root->value;
    }
    if(output.empty() && root->left != nullptr){
        output = search_helper(root->left, search_name);
    }
    if(output.empty() && root->right != nullptr){
        output = search_helper(root->right, search_name);
    }
    return output;
}

// BST Copy Helper Method used only by num_constants method.
Node* copy_helper(Node *node){
    if (node == nullptr){
        return nullptr;
    }

    Node *copy = new Node;
    copy->name = node->name;
    copy->value = node->value;

    copy->left = copy_helper(node->left);
    copy->right = copy_helper(node->right);

    return copy;
}

// BST Num Constants Helper Method used only by Num constants method.
int num_helper(Node *root){
    int count = 0;
    if (root != nullptr){
        count++;
    }
    if (root->left != nullptr){
        count += num_helper(root->left);
    }
    if (root->right != nullptr){
        count += num_helper(root->right);
    }
    return count;
}

// BST Destructor Helper Method used only by destructor
void destructor_helper(Node *root){
    if(root == nullptr){
        return;
    }
    destructor_helper(root->right);
    destructor_helper(root->left);

    delete root;
}

// creates a new binary search tree with no data inside
BST::BST()
{
    this->root = nullptr;
}

// Copy Constructor for BST class.
// Parameters:
// other: BST object to be copied
BST::BST(const BST &other)
{
    root = copy_helper(other.root);
}

// Destructor for the BST class. frees all heap-allocated memory.
BST::~BST()
{
    destructor_helper(root);
}

// returns the BST names and values as a string
string BST::to_string() const
{
    string ret = to_string_helper(this->root);
    if(ret.length() > 1)
    {
         ret.pop_back(); //remove final space
    }
    return ret;
}

// inserts new value and name into tree
// Parameters:
// name: name of item to be added
// value: value of item to be added
void BST::insert_constant(string name, string value)
{
    insert_helper(*&this->root, name, value);
}

// returns the value of a name located inside the tree
// Parameters:
// name: name of value to collect
string BST::get_value(string name) const
 {
    return search_helper(*&this->root, name);
 }

// returns number of items stored in tree
int BST::num_constants() const
{
    return num_helper(*&this->root);
}

// Copy Assignment Operator for BST class.
// Parameters:
// rhs: target for assignment
BST& BST::operator=(const BST &rhs)
{
    destructor_helper(root);
    root = copy_helper(rhs.root);
    return *this;
}
