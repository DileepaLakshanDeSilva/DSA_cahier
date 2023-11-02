#include "IteamList.h"
#include <iomanip>
#include<string>
#include<fstream>
#include <Windows.h>

using namespace std;

int GetConsoleWidth1()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwSize.X;
}

void SetConsoleColor1(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

ItemList::ItemList() //Defalt case
{
	head = NULL;
	tail = NULL;
	size = 0;
}


void ItemList::insertItem(string Product, int Cost)
{

	node* temp = new node(Product, Cost);

	if (size == 0) 
	{
		head = tail = temp;

	}
	else 
	{
		tail->next = temp;
		temp->preve = tail;
		tail = temp;
	}
	size++;
//	fileWrite();
	//cout << "task added" << endl;
}

int ItemList::printLinkedList()
{
	system("cls");
	cout << "\n\n\n\n\n";
	node* current = head;
	int consoleWidth = GetConsoleWidth1();
	int space = (consoleWidth - textLength) / 2;
	int totalCost = 0;
	if (size == 0) 
	{
		SetConsoleColor1(FOREGROUND_RED);
		cout << setw(space) << "				No Items" << endl;
		SetConsoleColor1(FOREGROUND_GREEN);
		return 0;
	}
	for (int i = 0; i < size; i++) 
	{
		cout << setw(space) << "         [" << i + 1 << "] " << current->product;
		cout << setw(space) << current->cost << endl;
		totalCost += current->cost;
		current = current->next;
	}
	cout << endl;

	SetConsoleColor1(FOREGROUND_RED);
	cout << setw(space) << "            " << "TOTAL COST IS :";
	cout << setw(space) << totalCost << endl;
	SetConsoleColor1(FOREGROUND_GREEN);
	return totalCost;

}

void ItemList::claerFile()
{
	node* curerent = head;

	if (size == 0) {

		return;
	}
	for (int i = 0; i < size; i++)
	{
		
			node* temp = NULL;
			temp = curerent;
			curerent = curerent->next;
			delete temp;

	}
	size = 0;
	cout << endl;
}