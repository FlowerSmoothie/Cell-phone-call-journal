#include "Decor.h"
#include "Constants.h"
#include <conio.h>
#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

void Separator()
{
	cout << "\n-----------------------------------\n";
}

void LittleSeparator()
{
	cout << "\n-----\n";
}


void ChangeColor(int color)
{
	HANDLE consoleColor;
	consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleColor, color);
}

void PrintHeader(string str, int color)
{
	ChangeColor(color);
	cout << "---------";
	cout << " " << str << " ";
	cout << "---------";
	cout << "\n";
	ChangeColor(15);
}

void DeleteSymbol()
{
	_putch('\b');
	_putch(' ');
	_putch('\b');
}

void SwitchWrongInput()
{
	cout << WRONG_INPUT << ' ' << ENTER_ANY_CHARACTER;
	cout << '\n';
	system("pause");
	system("cls");
}

bool IsDigit(char c)
{
	if (c >= 48 && c<=57)
		return true;
	return false;
}

bool IsEngLetter(char c)
{
	if ((c>= 'A' && c<= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	return false;
}

string EnterNumberInString()
{
	string str;
	char c;
	while (1)
	{
		c = _getch();
		if (c == ENTER)
		{
			if (str.size() == 0)
				continue;
			else
				break;
		}
		if (c == 8)
		{
			if (str.size() == 0)
				continue;
			str.pop_back();
			DeleteSymbol();
		}
		if (IsDigit(c) == 0)
		{
			continue;
		}
		str.append(1, c);
		_putch(c);
	}
	return str;
}

void DeleteAllFromFile()
{
	ofstream UFile;
	UFile.open(DATABASE_FILE, ofstream::trunc);
	UFile.close();
}

int NumberInputCheck(int index, int size)
{
	if (index > size && index < 1)
	{
		std::cout << WRONG_INPUT << endl;
		std::system("pause");
		return 0;
	}
	return 1;
}

double EnterDouble()
{
	string str;
	char c;
	while (1)
	{
		c = _getch();
		if (c == ENTER)
		{
			if (str.size() == 0)
				continue;
			else
				break;
		}
		if (c == 8)
		{
			if (str.size() == 0)
				continue;
			str.pop_back();
			DeleteSymbol();
		}
		if (IsDigit(c) == 0 && c != 46)
		{
			continue;
		}
		str.append(1, c);
		_putch(c);
	}
	return stod(str);
}

int EnterNumber()
{
	string str = EnterNumberInString();
	return stoi(str);
}

bool IsCyrLetter(char c)
{
	if ((c>= -64 && c<= -33) || (c >= -32 && c <= -1))
		return true;
	return false;
}

int SymbolCheck(char c)
{
	if(IsEngLetter(c) || IsDigit(c) || IsCyrLetter(c) || c == 96 || c == 92)
		return 1;
	else
		return 0;
}
