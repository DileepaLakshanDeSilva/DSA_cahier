#include <iostream>
#include<string>
#include <iomanip>
#include <Windows.h>
#include "Queue.h"

using namespace std;

void SetConsoleColor4(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



void caffeitam(int spaces, QueueArray* Queue)
{
	int t = 1;

	while (t)
	{
		cout << endl;
		cout << setw(spaces) << "" << "        [0] GO FOODCITY       " << endl;
		cout << setw(spaces) << "" << "        [1] Place Order       " << endl;
		cout << setw(spaces) << "" << "        [2] Visit Orders       " << endl;
		cout << endl;
		cout << endl;
		SetConsoleColor4(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << setw(spaces) << "" << "Enter Number : " ;
		SetConsoleColor4(FOREGROUND_GREEN);
		int num;
		cin >> num;
		SetConsoleColor4(FOREGROUND_BLUE);
		cout << endl;

		if (num == 0)
		{
			return;
		}
		else if (num == 1)
		{
			cout << setw(spaces) << "" << "Enter Order : ";
			SetConsoleColor4(FOREGROUND_GREEN);
			string order;
			cin >> order;
			SetConsoleColor4(FOREGROUND_BLUE);
			cout << endl;

			Queue->enQueue(order);
			
			
		}
		else if (num == 2)
		{
			system("cls");
			cout << "\n\n\n";
			SetConsoleColor4(FOREGROUND_GREEN);
			cout << setw(spaces) << "" << "        " << "**** NEXT ORDER ****\n\n";
			SetConsoleColor4(FOREGROUND_RED);
			cout << setw(spaces) << "" << "        ";
			Queue->print();
			cout << endl;
			SetConsoleColor4(FOREGROUND_BLUE);
			cout << setw(spaces) << "" << "        [0] Back       " << endl;
			cout << setw(spaces) << "" << "        [1] Finish Order       " << endl;
			cout << endl;
			SetConsoleColor4(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << setw(spaces) << "" << "Enter Number : ";
			SetConsoleColor4(FOREGROUND_GREEN);
			int num2;
			cin >> num2;
			SetConsoleColor4(FOREGROUND_BLUE);
			cout << endl;

			if (num2 == 1)
			{
				SetConsoleColor4(FOREGROUND_RED);
				cout << setw(spaces) << "" << "        ";
				Queue->deQueue();
				SetConsoleColor4(FOREGROUND_BLUE);
			}

		}
		else
		{
			SetConsoleColor4(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "Please enter number again" << endl;
		}
	}
}