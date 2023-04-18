#include <string>
#include "BST.h"
using namespace std;


string to_string_helper(Node *root);
void insert_helper(Node *&root, const string& name, const string& value);
string search_helper(Node *root, const string& search_name);
Node* copy_helper(Node *node);
void destructor_helper(Node *root);

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

string search_helper(Node *root, const string& search_name){
    string output;
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

void destructor_helper(Node *root){
    if(root == nullptr){
        return;
    }
    destructor_helper(root->right);
    destructor_helper(root->left);

    delete root;
}

BST::BST()
{
    this->root = nullptr;
}

// Creates a binary search_helper tree by copying all the constant value pairs
// from the existing binary search_helper tree.
BST::BST(const BST &other)
{
    root = copy_helper(other.root);
}

// Destructor for the BST class. frees all heap-allocated memory.
BST::~BST()
{
    destructor_helper(root);
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
    insert_helper(*&this->root, name, value);
}

// Returns the value that corresponds to (name),
// Returns "" if name does not exist.
string BST::get_value(string name) const
 {
    return search_helper(*&this->root, name);
 }

// Returns number of constant value pairs
int BST::num_constants() const
{
    return num_helper(*&this->root);
}

BST& BST::operator=(const BST &rhs)
{
    destructor_helper(root);
    root = copy_helper(rhs.root);
    return *this;
}
