#pragma once
#include <string>

using namespace std;

struct UserStruct
{
	string login;
	string password;
	int role;
	int access;
};

void AdminMenu();
void ViewUsers();
void WriteInfoAboutUserOnScreen(UserStruct user, int index);
void ViewUsers();
void DeleteUser();
