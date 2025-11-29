#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Abonent
{
private:
	string fio; // имя
	string tarif; // название тарифа
	int phone; // номер телефона
	int year; // год подключения

public:
	void add_abo();
	void delete_abo();
	void edit_abo();
	void view_abo();
	void search_abo();
	void sort_abo();
	void Task();

protected:
	string Information = "information.txt";
};