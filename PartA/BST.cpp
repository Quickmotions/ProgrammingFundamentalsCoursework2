#include <string>
#include "BST.h"
using namespace std;

string to_string_helper(Node *root); //Prototype of a helper function,
									 //You can add additional helper functions
									//to this code file

BST::BST()
{
    this->root = nullptr;
}


BST::BST(const BST &other)
{
   //TODO: Implement the copy constructor
}


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

string BST::to_string() const
{
    string ret = to_string_helper(this->root);
    if(ret.length() > 1)
    {
         ret.pop_back(); //remove final space
    }
   
    return ret;
}



void BST::insert_constant(string name, string value)
{
   //TODO: Implement the insert_constant method
}


string BST::get_value(string name) const
 {
    return ""; //TODO: Change this to implement the get_value() method
 }



int BST::num_constants() const
{
    return -1; //TODO: Change this to implement the num_constants() method
}


BST& BST::operator=(const BST &rhs)
{
    
	return *this; //TODO: Add code here to implement the = operator
}
