#pragma once
#include "User.h"
class Admin : public User
{
public:
	void Admin_Menu();
	void Delete_All_Users();
	void Delete_User();
	void View_All_Users();
	void Edit_User();
};
