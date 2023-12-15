#pragma once
#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    string product;
    int cost;
    node* next, * preve;

    // Constructors
    node();  // Default constructor
    node(string Product, int Cost);  // Overloaded constructor

    // Destructor
    ~node();  // Destructor
};
