#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <fstream>
#include "IteamList.h"
#include "node.h"

using namespace std;

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



void MainMenu(int spaces) 
{
   // int result = 0;

    cout << endl;
    cout << setw(spaces) << "" << "        [0] Show your Items        " << endl;
    cout << setw(spaces) << "" << "        [1] Remove a Item          " << endl;
    cout << setw(spaces) << "" << "        [2] Remove All       " << endl;
    cout << setw(spaces) << "" << "        [3] PAY\n" << endl;

  //  cout << setw(spaces) << "What do you want : ";
  //  cin >> result;

  //  return result;
}

int mainmenuInputHandler(string value, ItemList& list, int spaces)
{
    

    if (value == "0")
    {
        SetConsoleColor(FOREGROUND_GREEN);
        list.printLinkedList();
        SetConsoleColor(FOREGROUND_BLUE);
        
    }
    else if (value == "1")
    {
        int deletePos;
        cout << setw(spaces) << "" << "        Plz enter what task dp you want to remove ?         ";
       
        cin >> deletePos;
        SetConsoleColor(FOREGROUND_GREEN);
        list.deleteTask(deletePos);
        SetConsoleColor(FOREGROUND_BLUE);
    }
    else if (value == "2")
    {
      list.claerFile();
    }
    else if (value == "3")
    {
        SetConsoleColor(FOREGROUND_GREEN);
        int fullCost = list.printLinkedList();
        SetConsoleColor(FOREGROUND_RED);

        int discountPercentage;

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

        int discount = (fullCost * discountPercentage / 100);
        int price = fullCost - discount;

        cout << endl;
        cout << setw(spaces) << "             " << "Discount ";
        cout << setw(40) <<right<< discount << endl;
        cout << endl;

        cout << setw(spaces) << "             " << "Last Cost ";
        cout << setw(40) << right<<price << endl;
        cout << endl;

        int cash;
        cout << setw(spaces) << "             " << "Enter Cash: ";
        cout << setw(spaces) << "";
        cin >> cash;
        cout << endl;
        int balance;
        balance = cash - price;
        cout << setw(spaces) << "             " << "Blance : ";
        cout << setw(spaces) << balance << endl;
        cout << endl;

        cout << setw(spaces) << "" << setw(spaces) << "Thank you for doing business with us." << endl;
        cout << endl;
        SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

        return 0;
    }
    else
    {
        int price;
        cout << setw(spaces) << "" << "Item price : ";
        cin >> price;
        cout << endl;
        addItem(list, spaces, value, price);
    }

    return 1;
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

    cout << setw(spaces) << "" << "Enter Item Name : ";
    cin >> item;
    cout << endl;
    cout << setw(spaces) << "" << "Item price : ";
    cin >> price;
    cout << endl;
    addItem(list1, spaces, item, price);
 

    while (t)
    {
        MainMenu(spaces);

        cout << setw(spaces) << "" << "Enter Item Name : ";
        cin >> item;
        cout << endl;
        t = mainmenuInputHandler(item, list1, spaces);
    }

}
