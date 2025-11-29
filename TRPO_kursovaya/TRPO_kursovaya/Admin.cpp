#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include<fstream>

using namespace std;

void Admin::View_All_Users()
{
	Registration R1;
	ifstream UserFile;
	string path = R1.getRegDATA();
	UserFile.open(path);
	if (!UserFile.is_open())
	{
		cout << "Enter opening data file!" << endl;
	}
	else
	{
		char ch;
		cout << "ALl user accounts" << endl;
		while (UserFile.get(ch))
		{
			cout << ch;
		}
	}
	UserFile.close();
	system("pause");
	system("cls");
}

void Admin::Delete_All_Users()
{
	Registration R1;
	ofstream UFile;
	string path = R1.getRegDATA();
	UFile.open(path, ofstream::trunc);
	cout << "All user accounts are deleted" << endl;
	system("pause");
	system("cls");
	UFile.close();
}

void Admin::Delete_User()
{
	int size = 0;
	ifstream InfFile;
	InfFile.open(getRegDATA());
	Registration R;
	while (InfFile.peek() != EOF)
	{
		InfFile >> R.LoginUser1; InfFile.get();
		InfFile >> R.PasswordUser1; InfFile.get();
		size++;
	}
	InfFile.close();

	int i = 0;
	Registration* arr = new Registration[size];
	ifstream InfFile1;
	InfFile1.open(getRegDATA());
	while (InfFile1.peek() != EOF)
	{
		InfFile1 >> arr[i].LoginUser1; InfFile1.get();
		InfFile1 >> arr[i].PasswordUser1; InfFile1.get();
		i++;
	}
	InfFile1.close();

	string tmp;
	int n = -1;
	cout << "Enter login of user that you would like to delete: "; cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (arr[j].LoginUser1 == tmp)
			n = j;
	}
	if (n == -1)
		cout << "There is no user with such login!" << endl;
	else {
		for (int j = n; j < size - 1; j++)
			arr[j] = arr[j + 1];
		size--;
	}
	ofstream InfFile2;
	InfFile2.open(getRegDATA());
	for (int j = 0; j < size; j++) {
		InfFile2 << arr[j].LoginUser1 << endl;
		InfFile2 << arr[j].PasswordUser1 << endl;
	}
	InfFile2.close();
	cout << "User" << " [" << tmp << "] " << "is deleted" << endl;
	delete[] arr;
	system("pause");
	system("cls");
}

void Admin::Admin_Menu()
{
	Registration R;
	bool exit = true;
	Admin A;
	while (exit)
	{
		cout << "----------- MENU ------------" << endl;
		cout << "1 - Show all accounts" << endl;
		cout << "2 - Add new account" << endl;
		cout << "3 - Delete one account" << endl;
		cout << "4 - Delete all accounts" << endl;
		cout << "5 - Show data about subscribers" << endl;
		cout << "6 - Add new subscriber" << endl;
		cout << "7 - Edit data about subscriber" << endl;
		cout << "8 - Delete subscriber" << endl;
		cout << "9 - Search for a subscriber" << endl;
		cout << "10 - Sort subscribers" << endl;
		cout << "11 - Individual task" << endl;
		cout << "0 - Back" << endl;
		int change1; cin >> change1; system("cls");
		switch (change1)
		{
		case 1:
			A.View_All_Users(); break;
		case 2:
			A.RegistrationFunction(); break;
		case 3:
			A.Delete_User(); break;
		case 4:
			A.Delete_All_Users(); break;
		case 5:
			view_abo(); break;
		case 6:
			add_abo(); break;
		case 7:
			edit_abo(); break;
		case 8:
			delete_abo(); break;
		case 9:
			search_abo(); break;
		case 10:
			sort_abo(); break;
		case 11:
			Task(); break;
		case 0:
			exit = false; break;
		default:
			cout << "Enter correct value!" << endl;
			break;
		}
	}
}