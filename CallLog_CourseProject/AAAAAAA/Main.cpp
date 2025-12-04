#include "Admin.h"
#include "Decor.h"
#include "LoginRegister.h"
#include "User.h"
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
	int result;
	char choice;
	while (1) {
		system("cls");
		PrintHeader("Phone call log program", 13);
		printf_s("\n 1 - log in \n 2 - sign in\n 3 - exit program\n");
		choice = _getch();
		switch (choice) {
		case '1':
			result = PrintLogInForm();
			switch (result) {
			case -1:
				continue;
			case 0:
				UserMenu();
				break;
			case 1:
				AdminMenu(); 
				break;
			}
			break;
		case '2':
			PrintRegistrationForm(0); 
			break;
		case '3':
			return 0;
		default:
			SwitchWrongInput(); 
			break;
		}
	}
	return 0;
}
