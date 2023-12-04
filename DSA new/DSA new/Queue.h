#pragma once
#include <iostream>

#include<string>
using namespace std;

class QueueArray
{
private:
	int capacity;
	int front;
	int rear;
	string* data;
	int size;

public:
	QueueArray(int cap);

	void enQueue(string val);

	string deQueue();

	void print();
};