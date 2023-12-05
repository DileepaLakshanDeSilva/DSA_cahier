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

QueueArray A1(20);

void SetConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawHirizontalLine(int cWidth)
{
    string line = "----------------------------------------";
    int spaces = (cWidth - line.length()) / 2;
    cout << setw(spaces) << "" << line << endl;
    SetConsoleColor(FOREGROUND_BLUE);
}



int GetConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}


void drawHeader(int spaces, int consoleWidth, string text)
{
    SetConsoleColor(FOREGROUND_BLUE);


    drawHirizontalLine(consoleWidth);
    SetConsoleColor(FOREGROUND_RED);
    cout << setw(spaces) << "" << text << endl;
    SetConsoleColor(FOREGROUND_BLUE);
    drawHirizontalLine(consoleWidth);

}


void addItem(ItemList& list, int spaces, string item, int price)
{
    list.insertItem(item, price);
}

void caffe()
{

    string text = "        HAPUGALA CAFFE        ";
    int consoleWidth = GetConsoleWidth();
    int spaces = (consoleWidth - text.length()) / 2;
    drawHeader(spaces, consoleWidth, text);
    caffeitam(spaces, &A1);

    system("cls");
    /*
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    string text = "        HAPUGALA FOODCITY        ";
    int consoleWidth = GetConsoleWidth();
    int spaces = (consoleWidth - text.length()) / 2;
    drawHeader(spaces, consoleWidth, text);
    */
}


void MainMenu(int spaces)
{

    cout << endl;
    cout << setw(spaces) << "" << "        [0] Show your Items        " << endl;
    cout << setw(spaces) << "" << "        [1] Remove a Item          " << endl;
    cout << setw(spaces) << "" << "        [2] Remove All       " << endl;
    cout << setw(spaces) << "" << "        [3] PAY" << endl;
    cout << setw(spaces) << "" << "        [4] Sarch in histroy" << endl;
    cout << setw(spaces) << "" << "        [5] GO Caffee\n" << endl;


}

int mainmenuInputHandler(string value, ItemList& list, int spaces)
{


    if (value == "0")
    {
        system("cls");
        SetConsoleColor(FOREGROUND_GREEN);
        list.printLinkedList();
        SetConsoleColor(FOREGROUND_BLUE);

    }
    else if (value == "1")
    {
        int deletePos;
        cout << setw(spaces) << "" << "        Plz enter what task you want to remove ?         ";

        cin >> deletePos;
        SetConsoleColor(FOREGROUND_GREEN);
        list.deleteTask(deletePos);
        SetConsoleColor(FOREGROUND_BLUE);
    }
    else if (value == "2")
    {
        list.claerFile();
    }
    else if (value == "5")
    {
        system("cls");
        
        caffe();
        string text = "        HAPUGALA FOODCITY        ";
        int consoleWidth = GetConsoleWidth();
        int spaces = (consoleWidth - text.length()) / 2;
        drawHeader(spaces, consoleWidth, text);

    }
    else if (value == "3")
    {
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
        string text;
        cout << setw(spaces) << "What good search ? :";
        SetConsoleColor(FOREGROUND_GREEN);
        cin >> text;
        SetConsoleColor(FOREGROUND_BLUE);
        list.fileRead(text);
    }
    else
    {
        checkout(spaces, list, value);
    }

    return 1;
}

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
        cout << setw(spaces) << "" << setw(spaces) << "Enter valid amount." << endl;
        system("pause");
        mainmenuInputHandler(value, list, spaces);
    }
    cout << setw(spaces) << "             " << "Blance :       ";  
    cout << setw(spaces) << balance << endl;
    cout << endl;
}

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
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int t = 1;

    string text = "        HAPUGALA FOODCITY        ";
    int consoleWidth = GetConsoleWidth();
    int spaces = (consoleWidth - text.length()) / 2;
    drawHeader(spaces, consoleWidth, text);

    ItemList list1;
    string item;
    int price;




    while (t)
    {
        MainMenu(spaces);

        cout << setw(spaces) << "" << "Enter Item Name : ";
        SetConsoleColor(FOREGROUND_GREEN);
        cin >> item;
        SetConsoleColor(FOREGROUND_BLUE);
        cout << endl;

        t = mainmenuInputHandler(item, list1, spaces);
    }

}