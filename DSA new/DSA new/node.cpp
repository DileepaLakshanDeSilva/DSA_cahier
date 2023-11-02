#include "node.h"

node::node() //defalt contructore
{
	product = "No Task ";
	cost = 0;
	next = NULL;
	preve = NULL;
}

node::node(string Product, int Cost) //overloaded constructore
{
	product = Product;
	cost = Cost;
	next = NULL;
	preve = NULL;
}