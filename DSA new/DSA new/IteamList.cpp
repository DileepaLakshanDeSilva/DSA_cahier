#include "IteamList.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

using namespace std;

// Function to get the console width
int GetConsoleWidth1()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}

// Function to set console text color
void SetConsoleColor1(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Constructor for ItemList class
ItemList::ItemList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

// Function to insert an item into the list
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

// Function to print the linked list and calculate the total cost
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

    cout << setw(space) << "         " << "ITEM" << setw(12) << right << "                                                   PRICE" << endl;
    cout << setw(space) << "         " << "----" << setw(12) << right << "                                                   -----" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << setw(space) << "         [" << i + 1 << "] " << setw(space) << left << current->product;
        cout << setw(12) << right << current->cost << endl;
        totalCost += current->cost;
        current = current->next;
    }

    cout << endl;

    SetConsoleColor1(FOREGROUND_RED);
    cout << setw(space) << "         " << "TOTAL COST IS :   ";
    cout << setw(40) << right << totalCost << endl;
    SetConsoleColor1(FOREGROUND_GREEN);
    return totalCost;
}

// Function to clear the linked list
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

// Function to delete the last item in the list
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

// Function to write the list to a file
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
            task << curerent->cost << endl;
            curerent = curerent->next;
        }

        task.close();
        cout << endl;
    }
    else {
        cout << "File not opened" << endl;
    }
}

// Function to read from a file and search for a specific item
void ItemList::fileRead(string text)
{
    fstream task;
    task.open("Tasklist.xlsx", ios::in);
    int consoleWidth = GetConsoleWidth1();
    int space = (consoleWidth - textLength) / 2;

    if (task.is_open()) {
        string line;
        int count = 0;

        while (getline(task, line)) {
            searchItem(line, text, count);
        }

        task.close();
        SetConsoleColor1(FOREGROUND_GREEN);
        cout << endl;
        std::cout << setw(space) << count << " Time sold" << std::endl;
        SetConsoleColor1(FOREGROUND_BLUE);
    }
}

// Function to search for a specific item
void ItemList::searchItem(string line, string PassText, int& count)
{
    if (PassText == line) {
        count++;
    }
}

// Function to delete the first item in the list
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

// Function to delete an item at a specific position in the list
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
