#include "Admin.h"
#include "Constants.h"
#include "Decor.h"
#include "LoginRegister.h"
#include "Talk.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

void WriteInfoAboutUserOnScreen(UserStruct user, int index) {
	cout << index + 1 << ". Login: " << user.login << "\n Password (cyphered): " << user.password << "\n Role: ";
	if (user.role == 1)
		cout << "administrator";
	else
		cout << "user";
	cout << "\n Account status: ";
	if (user.access == 0)
		cout << "not active";
	else if (user.access == 1)
		cout << "active";
	else
		cout << "blocked";
}

void WriteUsersToFile(vector<UserStruct> arr) {
	ofstream Ffile;
	Ffile.open(USER_DATA_FILE);
	for (int i = 0; i < arr.size(); i++) {
		Ffile << arr[i].login << endl;
		Ffile << arr[i].password << endl;
		Ffile << arr[i].role << endl;
		Ffile << arr[i].access << endl;
	}
	Ffile.close();
}

vector<UserStruct> ReadUsersFromFile() {
	vector <UserStruct> arr;
	UserStruct user;
	ifstream readFile;
	readFile.open(USER_DATA_FILE);
	for (int i = 0; readFile.peek() != EOF; i++) {
		readFile >> user.login; readFile.get();
		readFile >> user.password; readFile.get();
		readFile >> user.role; readFile.get();
		readFile >> user.access; readFile.get();
		arr.push_back(user);
	}
	readFile.close();
	return arr;
}

void ViewUsers(vector<UserStruct> arr) {
	UserStruct user;
	int s = arr.size();
	for (int i = 0; i < s; i++) {
		WriteInfoAboutUserOnScreen(arr[i], i + 1);
		LittleSeparator();
	}
}

void ViewUsers() {
	vector<UserStruct> arr;
	arr = ReadUsersFromFile();
	ViewUsers(arr);
	cout << endl;
	system("pause");
	system("cls");
}

vector<UserStruct> SearchForUser(vector<UserStruct> arr, string str, int task) {
	int found = 0;
	char choice;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].login == str) {
			switch (task) {
			case 1:
				ChangeColor(12);
				cout << "Confirm deletion: press 1 to continue or any other key to cancel. ";
				ChangeColor(15);
				choice = _getch();
				if (choice != '1')
					break;
				arr.erase(arr.begin() + i);
				found = 1;
				cout << endl;
				break;
			case 2:
				arr[i].access = 1;
				found = 1;
				break;
			case 3:
				if (arr[i].access != 2)
					arr[i].access = 2;
				else
					arr[i].access = 1;
				found = 1;
				break;
			}
		}
	}
	if (found == 0) {
		cout << "No user with such login!" << endl;
	}
	return arr;
}

void DeleteUser() {
	vector<UserStruct> arr;
	arr = ReadUsersFromFile();
	string str;
	cout << "Enter login of a user to delete: ";
	cin >> str;
	arr = SearchForUser(arr, str, 1);
	DeleteAllFromFile();
	WriteUsersToFile(arr);
	cout << endl;
	system("pause");
	system("cls");
}

void ActivateUser() {
	vector<UserStruct> arr = ReadUsersFromFile();
	string str;
	cout << "Enter login of an account to activate: ";
	cin >> str;
	arr = SearchForUser(arr, str, 2);
	DeleteAllFromFile();
	WriteUsersToFile(arr);
	cout << endl;
	system("pause");
	system("cls");
}

void BlockUnblockUser() {
	vector<UserStruct> arr;
	arr = ReadUsersFromFile();
	string str;
	cout << "Enter login of an account you would like to block/unblock: ";
	cin >> str;
	arr = SearchForUser(arr, str, 3);
	DeleteAllFromFile();
	WriteUsersToFile(arr);
	cout << endl;
	system("pause");
	system("cls");
}

void AdminMenu() {
	char choice;
	while (1) {
		system("cls");
		PrintHeader("Menu", 13);
		cout << " 1 - Operations with accounts\n 2 - Operations with calls\n 3 - Exit\n ";
		choice = _getch();
		system("cls");
		switch (choice) {
		case '1':
			PrintHeader("Operations with accounts", 13);
			cout << "1 - Show all accounts\n 2 - Add new administrator\n 3 - Delete account\n 4 - Activate account\n 5 - Block/unblock account\n 6 - Go back\n 7 - Exit\n ";
			choice = _getch();
			switch (choice)
			{
			case '1':
				ViewUsers(); break;
			case '2':
				PrintRegistrationForm(1); break;
			case '3':
				DeleteUser(); break;
			case '4':
				ActivateUser(); break;
			case '5':
				BlockUnblockUser(); break;
			case '6':
				break;
			case '7':
				cout << "Press 1 to exit or other key to stay: ";
				choice = _getch();
				if (choice == '1')
					return;
				break;
			default:
				SwitchWrongInput(); break;
			}
			break;
		case '2':
			PrintHeader("Call operations", 13);
			cout << "1 - Show data about calls\n 2 - Add new call data\n 3 - Edit call data\n 4 - Delete call\n 5 - Filter calls\n 6 - Sort calls\n 7 - Individual task\n 8 - Search calls\n 9 - Back\n 0 - Exit\n ";
			choice = _getch();
			switch (choice) {
			case '1':
				cout << '\n';
				ViewTalk();
				break;
			case '2':
				AddTalk(); break;
			case '3':
				cout << '\n';
				ViewTalk();
				cout << '\n';
				EditTalk();
				break;
			case '4':
				DeleteTalk(); break;
			case '5':
				SearchTalk(); break;
			case '6':
				SortTalk(); break;
			case '7':
				Task(); break;
			case '8':
				SearchTalk(); break;
			case '9':
				break;
			case '0':
				cout << "Press 1 to exit or other key to stay: ";
				choice = _getch();
				if (choice == '1')
					return;
			default:
				SwitchWrongInput(); break;
			}
			break;
		case '3':
			cout << "Press 1 to exit or other key to stay: ";
			choice = _getch();
			if (choice == '1')
				return;
			else
				break;
		default:
			SwitchWrongInput(); break;
		}
	}
}
