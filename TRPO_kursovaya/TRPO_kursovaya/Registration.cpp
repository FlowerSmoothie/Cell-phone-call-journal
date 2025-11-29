#include "Registration.h"
#include "Hash.h"
#include <iostream>
#include <fstream>


void Registration::RegistrationFunction()
{
	cout << "----------- Registration -------------" << endl;
	cout << "Enter login: "; cin >> LoginUser;
	cout << "Enter password:"; cin >> PasswordUser;
	ofstream RegFile;
	RegFile.open(RegDATA, ofstream::app);
	RegFile << LoginUser << endl;
	RegFile << hash.getHash(PasswordUser) << endl;
	RegFile.close();
	system("pause");
	system("cls");
}

void Registration::EnterToProgram()
{
	int exit1 = true;
	while (exit1)
	{
		cout << "1 - Enter user mode" << endl;
		cout << "2 - Enter admin mode" << endl;
		cout << "0 - Back" << endl;
		int change;
		cin >> change;
		system("cls");
		string log, log1, pass, pass1;
		ifstream fileIN;
		switch (change)
		{
		case 1:
			cout << "Login: ";
			cin >> log;
			cout << "Password: ";
			cin >> pass;
			fileIN.open(RegDATA);
			if (!fileIN.is_open()) {
				cout << "An error occured while opening login data file!" << endl;
				Access = 0;
			}
			else {
				ifstream fileIN;
				fileIN.open(RegDATA);
				while (fileIN.peek() != EOF)
				{
					fileIN >> LoginUser; fileIN.get();
					fileIN >> hash.getHash(PasswordUser); fileIN.get();
					if (log == LoginUser && hash.getHash(pass) == hash.getHash(PasswordUser)) {
						Access = 1;
						Role = 0;
						break;
					}
					else { Access = 0; Role = 0; }
				}
			}
			fileIN.close();
			system("cls");
			exit1 = false;
			break;
		case 2:
			cout << "Login: "; cin >> log;
			cout << "Password: "; cin >> pass;
			system("cls");
			if (log == LoginAdmin && hash.getHash(pass) == hash.getHash(PasswordAdmin)) {
				Access = 1; Role = 1;
			}; exit1 = false; break;
		case 0:
			exit1 = false; break;
		default:
			cout << "Enter correct value!" << endl;
			break;
		}
	}

}

string Registration::getRegDATA()
{
	return RegDATA;
}
