#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <fstream>
#include "IteamList.h"
#include "node.h"
#include "DSA new.h"
#include "caffe.h"
#include "Queue.h"

using namespace std;

// Global QueueArray object A1
QueueArray A1(20);

// Function to set console text color
void SetConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to draw a horizontal line centered on the console
void drawHirizontalLine(int cWidth)
{
    string line = "----------------------------------------";
    int spaces = (cWidth - line.length()) / 2;
    cout << setw(spaces) << "" << line << endl;
    SetConsoleColor(FOREGROUND_BLUE);
}

// Function to get the width of the console
int GetConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}

// Function to draw a header with a centered text
void drawHeader(int spaces, int consoleWidth, string text)
{
    SetConsoleColor(FOREGROUND_BLUE);
    drawHirizontalLine(consoleWidth);
    SetConsoleColor(FOREGROUND_RED);
    cout << setw(spaces) << "" << text << endl;
    SetConsoleColor(FOREGROUND_BLUE);
    drawHirizontalLine(consoleWidth);
}

// Function to add an item to the ItemList
void addItem(ItemList& list, int spaces, string item, int price)
{
    list.insertItem(item, price);
}

// Function for the cafe menu
void caffe()
{
    // Display cafe header
    string text = "        HAPUGALA CAFFE        ";
    int consoleWidth = GetConsoleWidth();
    int spaces = (consoleWidth - text.length()) / 2;
    drawHeader(spaces, consoleWidth, text);
    caffeitam(spaces, &A1);

    system("cls");
}

// Function to display main menu options
void MainMenu(int spaces)
{
    cout << endl;
    cout << setw(spaces) << "" << "        [0] Show your Items        " << endl;
    cout << setw(spaces) << "" << "        [1] Remove a Item          " << endl;
    cout << setw(spaces) << "" << "        [2] Remove All       " << endl;
    cout << setw(spaces) << "" << "        [3] PAY" << endl;
    cout << setw(spaces) << "" << "        [4] Search in history" << endl;
    cout << setw(spaces) << "" << "        [5] GO Caffee\n" << endl;
}

// Function to handle user input for main menu
int mainmenuInputHandler(string value, ItemList& list, int spaces)
{
    if (value == "0")
    {
        // Show items
        system("cls");
        SetConsoleColor(FOREGROUND_GREEN);
        list.printLinkedList();
        SetConsoleColor(FOREGROUND_BLUE);
    }
    else if (value == "1")
    {
        // Remove an item
        int deletePos;
        cout << setw(spaces) << "" << "        Plz enter what task you want to remove ?         ";
        cin >> deletePos;
        SetConsoleColor(FOREGROUND_GREEN);
        list.deleteTask(deletePos);
        SetConsoleColor(FOREGROUND_BLUE);
    }
    else if (value == "2")
    {
        // Remove all items
        list.claerFile();
    }
    else if (value == "5")
    {
        // Go to cafe
        system("cls");
        caffe();
        string text = "        HAPUGALA FOODCITY        ";
        int consoleWidth = GetConsoleWidth();
        int spaces = (consoleWidth - text.length()) / 2;
        drawHeader(spaces, consoleWidth, text);
    }
    else if (value == "3")
    {
        // Checkout and payment
        SetConsoleColor(FOREGROUND_GREEN);
        int fullCost = list.printLinkedList();
        SetConsoleColor(FOREGROUND_RED);

        int discountPercentage;
        DiscountCalculation(fullCost, discountPercentage);

        int discount = (fullCost * discountPercentage / 100);
        int price = fullCost - discount;

        cout << endl;
        checkOut(spaces, discount, price, value, list);

        list.fileWrite();

        SetConsoleColor(FOREGROUND_GREEN);
        cout << setw(spaces) << "" << setw(spaces) << "Thank you for doing business with us." << endl;
        cout << endl;
        SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        system("pause");

        return 0;
    }
    else if (value == "4") {
        // Search in history
        string text;
        cout << setw(spaces) << "What good search ? :";
        SetConsoleColor(FOREGROUND_GREEN);
        cin >> text;
        SetConsoleColor(FOREGROUND_BLUE);
        list.fileRead(text);
    }
    else
    {
        // Add item to the cart
        checkout(spaces, list, value);
    }

    return 1;
}

// Function to handle checkout process
void checkOut(int spaces, int discount, int price, std::string& value, ItemList& list)
{
    cout << setw(spaces) << "             " << "Discount          ";
    cout << setw(40) << right << discount << endl;
    cout << endl;

    cout << setw(spaces) << "             " << "Last Cost         ";
    cout << setw(40) << right << price << endl;
    cout << endl;

    int cash;
    cout << setw(spaces) << "             " << "Enter Cash: ";
    cout << setw(spaces) << "";
    cin >> cash;
    cout << endl;
    int balance;
    balance = cash - price;
    if (balance < 0) {
        cout << endl;
        cout << setw(spaces) << "" << setw(spaces) << "Enter a valid amount." << endl;
        system("pause");
        mainmenuInputHandler(value, list, spaces);
        return;
    }
    cout << setw(spaces) << "             " << "Balance :       ";
    cout << setw(spaces) << balance << endl;
    cout << endl;
}

// Function to calculate discount based on total cost
void DiscountCalculation(int fullCost, int& discountPercentage)
{
    if (fullCost < 1000)
    {
        discountPercentage = 0;
    }
    else if (fullCost < 3000)
    {
        discountPercentage = 5;
    }
    else if (fullCost < 5000)
    {
        discountPercentage = 7;
    }
    else if (fullCost < 10000)
    {
        discountPercentage = 10;
    }
    else
    {
        discountPercentage = 20;
    }
}

// Function to handle adding items to the cart
void checkout(int spaces, ItemList& list, std::string& value)
{
    float price, oneItimePrice, itemCount;
    cout << setw(spaces) << "" << "Item price : ";
    SetConsoleColor(FOREGROUND_GREEN);
    cin >> oneItimePrice;
    SetConsoleColor(FOREGROUND_BLUE);
    cout << setw(spaces) << "" << "How many Items Do you have : ";
    SetConsoleColor(FOREGROUND_GREEN);
    cin >> itemCount;
    price = itemCount * oneItimePrice;
    cout << endl;
    SetConsoleColor(FOREGROUND_BLUE);
    addItem(list, spaces, value, price);
}

int main()
{
    // Initialize console
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int t = 1;

    // Display main header
    string text = "        HAPUGALA FOODCITY        ";
    int consoleWidth = GetConsoleWidth();
    int spaces = (consoleWidth - text.length()) / 2;
    drawHeader(spaces, consoleWidth, text);

    // Create ItemList object
    ItemList list1;
    string item;
    int price;

    // Main program loop
    while (t)
    {
        // Display main menu
        MainMenu(spaces);

        cout << setw(spaces) << "" << "Enter Item Name : ";
        SetConsoleColor(FOREGROUND_GREEN);
        cin >> item;
        SetConsoleColor(FOREGROUND_BLUE);
        cout << endl;

        // Handle user input for main menu
        t = mainmenuInputHandler(item, list1, spaces);
    }
}
