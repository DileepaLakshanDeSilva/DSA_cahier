#pragma once
#include <iostream>
#include<string>
using namespace std;
class node
{
public:
	string product;
	int cost;
	node* next, * preve;


	node();//defalt contructore
	node(string Product, int Cost);//overloaded constructore
};