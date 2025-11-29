#pragma once
#pragma once
#include "Abonents.h"
#include "Registration.h"
class User : public Abonent, public Registration
{
public:
	void User_Menu();
};