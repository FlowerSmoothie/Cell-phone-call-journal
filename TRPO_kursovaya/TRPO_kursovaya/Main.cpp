#include <string>
#include <fstream>
#include <iostream>
#include "Registration.h"
#include "Abonents.h"
#include "Admin.h"
#include"User.h"
#include "Hash.h"
using namespace  std;

int main()
{
	int change = -1;
	bool exit = true;

	Registration R;
	Admin A;
	User U;

	while (exit)
	{
		cout << "---------- Cellular Subscribers -----------" << endl;
		cout << "1 - Enter Program \n2 - User Registration \n3 - Exit Program" << endl;;
		cin >> change;
		system("cls");
		switch (change)
		{
		case 1:
			R.EnterToProgram();
			if (R.Access == 1 && R.Role == 1) {
				A.Admin_Menu();
				R.Role = 0;
				R.Access = 0;
			}
			else if (R.Access == 1 && R.Role == 0) {
				U.User_Menu();
				R.Role = 0;
				R.Access = 0;
			}
			else {
				cout << "Login or password is not correct!" << endl;
				system("pause");
				system("cls");
			}break;
		case 2:
			R.RegistrationFunction(); break;
		case 3:
			exit = false; break;
		default:
			cout << "Enter correct value!" << endl;
			break;
		}
	}
	return 0;
}