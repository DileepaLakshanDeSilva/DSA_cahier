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
		cout << setw(space) << "                 No Items" << endl;
		SetConsoleColor1(FOREGROUND_GREEN);
		return 0;
	}

	cout << setw(space) << "         " << "ITEM" << setw(12) <<right<< "                                                   PRICE" << endl;
	cout << setw(space) << "         " << "----" << setw(12) <<right<< "                                                   -----" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(space) << "         [" << i + 1 << "] " << setw(space) << left << current->product;
		cout << setw(12) << right << current->cost << endl;
		totalCost += current->cost;
		current = current->next;
	}

	cout << endl;

	SetConsoleColor1(FOREGROUND_RED);
	cout << setw(space) << "         " << "TOTAL COST IS :";
	cout << setw(40) << right << totalCost << endl;
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

void ItemList::deleteTaskLast()
{
	if (size == 0) {
		cout << "Your list is empty " << endl;
	}
	else {
		node* temp = tail;
		tail = temp->preve;
		
		delete temp;
		size--;
		
	}
}

void ItemList::fileWrite()
{
	
	task.open("Tasklist.xlsx", ios::app);

	if (task.is_open())
	{
		node* curerent = head;
		if (size == 0) {
			
			return;
		}
		for (int i = 0; i < size; i++) {
			
				task << curerent->product << endl;
				task<< curerent->cost << endl;
			
			
			curerent = curerent->next;
		}
		task.close();
		cout << endl;
	}
	else {
		cout << "File note opened" << endl;
	}
	
}

void ItemList::fileRead()
{

	fstream task;
	task.open("Tasklist.txt", ios::in);
	int consoleWidth = GetConsoleWidth1();
	int space = (consoleWidth - textLength) / 2;
	if (task.is_open()) {

		if (task.peek() == std::ifstream::traits_type::eof()) {
			std::cout << setw(space) << " " << "      The file is empty." << std::endl;
		}
		else {
			std::cout << setw(space) << " " << "      The file is not empty." << std::endl;
		}

		/*string line;
		while (getline(task, line)) {
			createLinkedList(line);
		}*/
		task.close();
	}
}



void ItemList::deleteTaskFirst()
{
	if (size == 0) {
		cout << "Your list is empty " << endl;
	}
	else {
		node* temp = head;
		head = temp->next;
		head->preve = NULL;
		delete temp;
		size--;
		fileWrite();

	}
}

void ItemList::deleteTask(int pos)
{
    if (pos <= 0 || pos > size)
    {
        cout << "Position is invalid" << endl;
        return;
    }

    if (size == 1 || pos == 1)
    {
        deleteTaskFirst();
    }
    else if (pos == size)
    {
        deleteTaskLast();
    }
    else
    {
        node* current = head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }

        node* temp = current;
        current->preve->next = current->next;
        current->next->preve = current->preve;
        delete temp;
        size--;
    }

    printLinkedList();
}





