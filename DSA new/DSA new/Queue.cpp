#include "Queue.h"
#include <iomanip>
#include<string>
#include<fstream>
#include <Windows.h>


using namespace std;

QueueArray :: QueueArray(int cap)
{
	capacity = cap;
	data = new string[capacity];
	size = 0;
	front = 0;
	rear = 0;
}

void QueueArray::enQueue(string val)
{
	if (size == capacity)
	{
		cout << "We can't accept the order yet" << endl;
	}
	else
	{
		data[rear] = val;
		rear = (rear + 1) % capacity;
		size++;

	}
}

string QueueArray::deQueue()
{
	if (size == 0)
	{
		cout << "We have no orders" << endl;
		return 0;
	}
	else
	{
		string temp = data[front];
		front = (front + 1) % capacity;
		size--;
		return temp;
	}
	
}



void QueueArray::print()
{
	if (size == 0)
	{
		cout << "We have no orders" << endl;
	}
	else
	{
		cout << data[front] << endl;
	}
}