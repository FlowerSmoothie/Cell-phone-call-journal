#include <conio.h>
#include <iostream>
#include "Decor.h"
#include "Talk.h"
#include "User.h"

using namespace std;

void UserMenu()
{
	char choice;
	while (1)
	{
		system("cls");
		PrintHeader("Menu", 13);
		printf("1 - Show data about calls\n 2 - Filter calls\n 3 - Sort calls\n 4 - Individual task\n 5 - Search calls\n 6 - Exit\n ");
		choice = _getch();
		system("cls");
		switch (choice)
		{
		case '1':
			ViewTalk();
			break;
		case '2':
			FilterTalk();
			break;
		case '3':
			SortTalk();
			break;
		case '4':
			Task();
			break;
		case '5':
			SearchTalk();
			break;
		case '6':
			printf("Press 1 to exit or other key to stay: ");
			choice = _getch();
			if (choice == '1')
				return;
			break;
		default:
			SwitchWrongInput();
			break;
		}
	}
}
