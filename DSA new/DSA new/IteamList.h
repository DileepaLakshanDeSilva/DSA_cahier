#pragma once
#include"node.h"
#include<string>
#include<fstream>

class ItemList
{
private:
	node* head;
	node* tail;
	int size;
	fstream task;
	const string text = "        HAPUGALA FOODCITY        ";
	int textLength = text.length();

public:
	ItemList();
	void insertItem(string Product, int Cost);
	int printLinkedList();
	void claerFile();
	void deleteTask(int pos);
	void deleteTaskFirst();
	void deleteTaskLast();
	void fileWrite();
	void fileRead();
};