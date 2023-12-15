#include "node.h"

// Default constructor
node::node()
{
    // Initialize default values
    product = "No Task ";
    cost = 0;
    next = NULL;
    preve = NULL;
}

// Overloaded constructor with parameters
node::node(string Product, int Cost)
{
    // Initialize values with provided parameters
    product = Product;
    cost = Cost;
    next = NULL;
    preve = NULL;
}

// Destructor
node::~node()
{
    // Optionally, you can include cleanup code here
    // This destructor is called when a node object goes out of scope or is explicitly deleted
}
