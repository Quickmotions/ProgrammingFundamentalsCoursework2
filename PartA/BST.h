#pragma once
#include <string>

struct Node
{
    Node *left;
    Node *right;
    std::string name;
    std::string value;
};

class BST
{
public:
    BST();
    BST(BST const &other);
    ~BST();
    BST& operator=(const BST &rhs);
    void insert_constant(std::string name, std::string value);
    std::string to_string() const;
    std::string get_value(std::string name) const;
    int num_constants() const;

private:
    Node *root;
};



