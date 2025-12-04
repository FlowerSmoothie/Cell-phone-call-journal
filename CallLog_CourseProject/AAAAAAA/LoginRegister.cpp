#include "Constants.h"
#include "Decor.h"
#include "Hash.h"
#include "LoginRegister.h"
#include <conio.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string EnterLogin() {
	string str;
	char c;
	while (1) {
		c = _getch();
		if (c == ENTER) {
			if (str.size() == 0)
				continue;
			else
				break;
		}
		if (c == 8) {
			if (str.size() == 0)
				continue;
			str.pop_back();
			DeleteSymbol();
		}
		if (SymbolCheck(c) == 0)
			continue;
		str.append(1, c);
		_putch(c);
	}
	return str;
}
string EnterPassword() {
	string str;
	char c;
	while (1) {
		c = _getch();
		if (c == ENTER) {
			if (str.size() == 0)
				continue;
			else
				break;
		}
		if (c == 8) {
			if (str.size() == 0)
				continue;
			str.pop_back();
			DeleteSymbol();
		}
		if (SymbolCheck(c) == 0)
			continue;
		str.append(1, c);
		_putch(HIDE_SYMBOL);
	}
	return str;
}
bool doPasswrodsMatch(string a, string b) {
	int size = a.size();
	if (size != b.size())
		return false;
	for (int i = 0; i < size; i++) {
		if (a[i] == b[i])
			continue;
		else
			return false;
	}
	return true;
}

bool createAccount(string login, string password, int role) {
	int exist = 0;
	string loginFromFile;
	string passwordFromFile;
	int access;
	int roleFromFile;
	ifstream file;
	file.open(USER_DATA_FILE);
	while (file.peek() != EOF) {
		file >> loginFromFile; file.get();
		file >> passwordFromFile; file.get();
		file >> roleFromFile; file.get();
		file >> access;	file.get();
		if (login == loginFromFile)
		{
			exist = 1;
			break;
		}
	}
	file.close();
	if (exist == 1) {
		printf_s("The login is already in use!\n");
		return false;
	}
	ofstream fileWrite;
	fileWrite.open(USER_DATA_FILE, ofstream::app);
	if (!fileWrite.is_open()) {
		printf_s("Unable to register.\n");
		return false;
	}
	fileWrite << login << endl;
	fileWrite << GetHash(password) << endl;
	fileWrite << role << endl;
	fileWrite << 0 << endl;
	fileWrite.close();
	return true;
}

void PrintRegistrationForm(int role) {
	string password;
	string checkPassword;
	string login;
	while (1) {
		system("cls");
		PrintHeader("New account registration", 13);
		printf_s("Enter login: ");
		login = EnterLogin();
		printf_s("\nEnter password: ");
		password = EnterPassword();
		printf_s("\nRepeat password: ");
		checkPassword = EnterPassword();
		Separator();
		if (doPasswrodsMatch(password, checkPassword)) {
			printf_s("Creating an account...");
			Separator();
			if (createAccount(login, password, role)) {
				cout << "Account created! " << ENTER_ANY_CHARACTER << '\n';
				system("pause");
				return;
			}
			else {
				cout << "Failed creating account. " << ENTER_ANY_CHARACTER << '\n';
				system("pause");
				return;
			}
		}
		else {
			cout << "Passwords do not match! " << ENTER_ANY_CHARACTER << '\n';
			system("pause");
		}
	}
}

int PrintLogInForm() {
	string password, login, loginFromFile, passwordFromFile;
	int found = 0, role = 0, access = 0;
	char choice;
	while (1) {
		system("cls");
		PrintHeader("Enter into account", 13);
		printf_s("Enter login: ");
		login = EnterLogin();
		printf_s("\nEnter password: ");
		password = EnterPassword();
		Separator();
		printf_s("\nTrying to log in...\n");
		Separator();
		ifstream file;
		file.open(USER_DATA_FILE);
		if (!file.is_open()) {
			printf_s("Unable to log in.\n");
			system("pause");
			return -1;
		}
		if (login == "admin" && password == "admin") {
			cout << "Logged in successfully! " << ENTER_ANY_CHARACTER << '\n';
			system("pause");
			return 1;
		}
		password = GetHash(password);
		while (file.peek() != EOF) {
			file >> loginFromFile; file.get();
			file >> passwordFromFile; file.get();
			file >> role; file.get();
			file >> access;	file.get();
			if ((login == loginFromFile) && (password == passwordFromFile)) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			printf_s("Check entered login and password.\n Press 1 to continue or other key to exit.\n");
			choice = _getch();
			if (choice == '1')
				continue;
			else
				return -1;
		}
		switch (access) {
		case 1:
			cout << "Logged in successfully! " << ENTER_ANY_CHARACTER << '\n';
			system("pause");
			return role;
			break;
		case 0:
			printf_s("Unable to log in! The account was not confirmed by administrator.\n");
			system("pause");
			return -1;
		case 2:
			printf_s("Unable to log in! The account was blocked by administrator.\n");
			system("pause");
			return -1;
		}
	}
}
