#include "User.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;


void User::User_Menu()
{
	User U;
	bool exitUM = true;
	while (exitUM)
	{
		cout << "---------- МЕНЮ ----------" << endl;
		cout << "1 - Просмотр данных об абонентах" << endl;
		cout << "2 - Поиск абонентов" << endl;
		cout << "3 - Сортировка абонентов" << endl;
		cout << "4 - Индивидуальное задание" << endl;
		cout << "0 - Назад" << endl;
		int change0;
		cin >> change0;
		system("cls");
		switch (change0)
		{
		case 1:
			view_abo(); break;
		case 2:
			search_abo(); break;
		case 3:
			sort_abo(); break;
		case 4:
			Task(); break;
		case 0:
			exitUM = false;
			system("cls");
			break;
		default:
			cout << "Неверно выбран пункт меню" << endl;
			break;
		}
	}

}
