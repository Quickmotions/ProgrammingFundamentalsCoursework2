//Author: Simon Powers
//Date of last modification: 20/03/23
//Test application for the BST class
#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int main()
{
	BST tree; //Make a BST object
	tree.insert_constant("PI", "3.142"); //Insert a single constant-value pair
	if(tree.to_string() == "PI=3.142")
	{
		cout << "Passed Test 1a: Insert single constant-value pair" << endl;
	}
	else
	{
		cout << "FAILED Test 1a: Insert single constant-value pair" << endl;
	}
	//Insert multiple constant-value pairs
	tree.insert_constant("SPEED_OF_LIGHT", "299792458");
	tree.insert_constant("X", "100");
	tree.insert_constant("Y", "50");
	tree.insert_constant("Z", "25");
	tree.insert_constant("E", "2.71828");
	tree.insert_constant("M", "555");
	tree.insert_constant("O", "100.4");
	tree.insert_constant("ALPHA", "400");
	if(tree.to_string() == "ALPHA=400 E=2.71828 M=555 O=100.4 PI=3.142 SPEED_OF_LIGHT=299792458 X=100 Y=50 Z=25")
	{
		cout << "Passed Test 1b: Insert multiple constant-vlaue pairs" << endl;
	}
	else
	{
		cout << "FAILED Test 1b: Insert multiple constant-vlaue pairs" << endl;
	}
	//Test getting values based on keys (constant names)
	string value1 =  tree.get_value("X");
	string value2 =  tree.get_value("PI");
	if(value1 == "100" && value2 == "3.142")
	{
		cout << "Passed Test 2: get_value from key" << endl;
	}
	else
	{
		cout << "FAILED Test 2: get_value from key" << endl;
	}
	//Test the num_constants() method returns the number of constant-value pairs inserted into the tree
	int num_constants1 = tree.num_constants();
	tree.insert_constant("LINE_LENGTH", "1000");
	int num_constants2 = tree.num_constants();
	if(num_constants1 == 9 && num_constants2 == 10)
	{
		cout << "Passed Test 3: num_constants" << endl;
	}
	else
	{
		cout << "FAILED Test 3: num_constants" << endl;
	}
	BST tree2; //Make another tree
	tree2.insert_constant("A", "10");
	tree2.insert_constant("B", "20");
	BST tree3(tree2); //Make a tree using the copy constructor
	tree2.insert_constant("C", "30"); //Checking for a deep copy by only modifying tree2 after copy
	if(tree2.to_string() == "A=10 B=20 C=30" && tree3.to_string() == "A=10 B=20")
	{
		cout << "Passed Test 4: Copy constructor" << endl;
	}
	else
	{
		cout << "FAILED Test 4: Copy constructor" << endl;
	}
	//Make two additional trees to test the assignment operator
	BST tree4;
	BST tree5;
	tree4.insert_constant("A", "10");
	tree4.insert_constant("B", "20");
	tree5 = tree4; //Testing assignment operator
	tree4.insert_constant("D", "40"); //Checking assignment has done a deep copy
	if(tree4.to_string() == "A=10 B=20 D=40" && tree5.to_string() == "A=10 B=20")
	{
		cout << "Passed Test 5: Assignment operator" << endl;
	}
	else
	{
		cout << "FAILED Test 5: Assignment operator" << endl;
	}
	return 0;
}

