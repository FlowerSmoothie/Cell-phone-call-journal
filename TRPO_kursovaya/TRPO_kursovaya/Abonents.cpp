#include "Abonents.h"
#include <iostream>
#include <fstream>
#include <vector>

void Abonent::add_abo()
{
	cout << "Enter name: ";
	cin >> fio;
	cout << "Enter phone number: ";
	cin >> phone;
	cout << "Enter tariff plan name: ";
	cin >> tarif;

	bool check = true;
	while (check) {
		cout << "Enter year of connection: ";
		cin >> year;
		if (year < 2000 && year > 2022)
			check = false;
	}

	ofstream InfFile;
	InfFile.open(Information, ofstream::app);
	InfFile << fio << endl;
	InfFile << phone << endl;
	InfFile << tarif << endl;
	InfFile << year << endl;
	InfFile.close();
	system("pause");
	system("cls");
}

void Abonent::delete_abo()
{
	vector <Abonent> Array;
	Abonent Abo;
	ifstream InfFile;
	InfFile.open(Information);
	while (InfFile.peek() != EOF)
	{
		InfFile >> Abo.fio; InfFile.get();
		InfFile >> Abo.phone; InfFile.get();
		InfFile >> Abo.tarif; InfFile.get();
		InfFile >> Abo.year; InfFile.get();
		Array.push_back(Abo);
		cout << "Имя:" << Abo.fio << endl;
	}
	InfFile.close();
	int size = Array.size();
	int n = -1;
	string tmp;
	cout << "Enter the name of the subscriber you would like to delete: "; cin >> tmp;
	for (int j = 0; j < Array.size(); j++) {
		if (Array[j].fio == tmp)
			n = j;
	}
	if (n == -1)
		cout << "There is no such data!" << endl;
	else {

		for (int j = n; j < size - 1; j++)
			Array[j] = Array[j + 1];
		size--;
	}

	// перезапись в файл
	ofstream InfFile2;
	InfFile2.open(Information);
	for (int j = 0; j < size; j++) {
		InfFile2 << Array[j].fio << endl;
		InfFile2 << Array[j].phone << endl;
		InfFile2 << Array[j].tarif << endl;
		InfFile2 << Array[j].year << endl;
	}
	InfFile2.close();
	cout << "Subscriber " << tmp << " is deleted" << endl;
	system("pause");
	system("cls");

}

void Abonent::edit_abo()
{
	vector<Abonent> Array;
	Abonent Abo;
	ifstream InfFile;
	InfFile.open(Information);
	while (InfFile.peek() != EOF)
	{
		InfFile >> Abo.fio; InfFile.get();
		InfFile >> Abo.phone; InfFile.get();
		InfFile >> Abo.tarif; InfFile.get();
		InfFile >> Abo.year; InfFile.get();
		Array.push_back(Abo);
		cout << "Name:" << Abo.fio << endl;
	}
	InfFile.close();
	int size = Array.size();
	string tmp;

	int n = -1;
	cout << "Enter the name of the subscriber data of whom you would like to edit: ";
	cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (Array[j].fio == tmp) {
			n = j;
			cout << endl;
			cout << "Subscriber's name: " << Array[j].fio << "\n";
			cout << "Subscriber's number: " << Array[j].phone << "\n";
			cout << "Tariff name:: " << Array[j].tarif << "\n";
			cout << "Year of connection: " << Array[j].year << "\n";
			system("pause");
			cout << endl;
		}

	}
	if (n == -1)
		cout << "No such data!" << endl;
	else {
		cout << "1 - Edit name" << endl;
		cout << "2 - Edit number" << endl;
		cout << "3 - Edit tariff number" << endl;
		cout << "4 - Edit year of connection" << endl;
		int change;
		cin >> change;
		int NewPhone, NewYear;
		string NewFio, NewTarif;
		switch (change)
		{
		case 1:
			cout << "Enter new name: ";
			cin >> NewFio;
			Array[n].fio = NewFio; break;
		case 2:
			cout << "Enter new number: ";
			cin >> NewPhone;
			Array[n].phone = NewPhone; break;
		case 3:
			cout << "Enter new tariff number: ";
			cin >> NewTarif;
			Array[n].tarif = NewTarif; break;
		case 4: {
			bool check = true;
			while (check) {
				cout << "Enter new year of connection: ";
				cin >> NewYear;
				if (NewYear < 2000 && NewYear > 2022)
					check = false;
			}
			Array[n].year = NewYear;
		}
			  break;
		default:
			cout << "No such data!" << endl;
			break;
		}
		cout << "Subscriber " << tmp << " data has changed successfully!" << endl;
	}
	// перезапись в файл
	ofstream InfFile2;
	InfFile2.open(Information);
	for (int j = 0; j < size; j++) {
		InfFile2 << Array[j].fio << endl;
		InfFile2 << Array[j].phone << endl;
		InfFile2 << Array[j].tarif << endl;
		InfFile2 << Array[j].year << endl;
	}
	InfFile2.close();
	system("pause");
	system("cls");
}

void Abonent::view_abo()
{
	Abonent Abo;
	ifstream InfFile1;
	InfFile1.open(Information);
	while (InfFile1.peek() != EOF)
	{
		InfFile1 >> Abo.fio; InfFile1.get();
		InfFile1 >> Abo.phone; InfFile1.get();
		InfFile1 >> Abo.tarif; InfFile1.get();
		InfFile1 >> Abo.year; InfFile1.get();
		cout << "Subscriber's name: " << Abo.fio << "\n";
		cout << "Subscriber's number: " << Abo.phone << "\n";
		cout << "Tariff name: " << Abo.tarif << "\n";
		cout << "Year of connection: " << Abo.year << "\n";
		cout << "-----------------------------------" << endl;
	}
	InfFile1.close();
	system("pause");
	system("cls");
}

void Abonent::search_abo()
{
	Abonent Abo;
	int trueSearch = 0;
	string NewFio;
	ifstream InfFile;
	InfFile.open(Information);
	cout << "Enter subscriber's name: "; cin >> NewFio;
	Abonent Search;
	while (InfFile.peek() != EOF)
	{
		InfFile >> Abo.fio; InfFile.get();
		InfFile >> Abo.phone; InfFile.get();
		InfFile >> Abo.tarif; InfFile.get();
		InfFile >> Abo.year; InfFile.get();
		if (NewFio == Abo.fio)
		{
			NewFio = Abo.fio;
			Search = Abo;
			trueSearch = 1;
		}
	}
	if (trueSearch == 1) {
		cout << endl;
		cout << "Subscriber's name: " << Abo.fio << "\n";
		cout << "Subscriber's number: " << Abo.phone << "\n";
		cout << "Tariff name: " << Abo.tarif << "\n";
		cout << "Year of connection: " << Abo.year << "\n";
		cout << "-----------------------------------" << endl;
		system("pause");
		cout << endl;
	}
	else {
		cout << "Data not found!" << endl;
	}
	InfFile.close();
	system("pause");
	system("cls");
}

void Abonent::sort_abo()
{
	vector<Abonent> Array;
	Abonent Abo;
	ifstream InfFile;
	InfFile.open(Information);
	while (InfFile.peek() != EOF)
	{
		InfFile >> Abo.fio; InfFile.get();
		InfFile >> Abo.phone; InfFile.get();
		InfFile >> Abo.tarif; InfFile.get();
		InfFile >> Abo.year; InfFile.get();
		Array.push_back(Abo);
	}
	InfFile.close();

	cout << "1 - Sort by name " << endl;
	cout << "2 - Sort by year of connection " << endl;
	int searchMenu;
	cin >> searchMenu;
	switch (searchMenu)
	{
	case 1: {
		system("cls");
		Abonent temp;
		int size = Array.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++) {
				if (Array[i].fio > Array[j].fio) {
					temp = Array[i];
					Array[i] = Array[j];
					Array[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << "Subscriber's name: " << Array[i].fio << "\n";
			cout << "Subscriber's number: " << Array[i].phone << "\n";
			cout << "Tariff name: " << Array[i].tarif << "\n";
			cout << "Year of connection: " << Array[i].year << "\n";
		}
		system("pause");
		system("cls");
	}break;
	case 2: {
		system("cls");
		Abonent temp;
		int size = Array.size();
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (Array[j].year > Array[j + 1].year) {
					// меняем элементы местами
					temp = Array[j];
					Array[j] = Array[j + 1];
					Array[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << "Subscriber's name: " << Array[i].fio << "\n";
			cout << "Subscriber's number: " << Array[i].phone << "\n";
			cout << "Tariff name: " << Array[i].tarif << "\n";
			cout << "Year of connection: " << Array[i].year << "\n";
		}
		system("pause");
		system("cls");
	}break;
	default:
		break;
	}
}

void Abonent::Task()
{
	vector<Abonent> Array;
	vector<Abonent> arr;
	Abonent Abo;
	int YEAR;
	bool check = true;
	while (check) {
		cout << "Enter year of connection: ";	cin >> YEAR;
		if (YEAR < 2000 && YEAR > 2022)
			check = false;
	}

	ifstream InfFile;
	InfFile.open(Information);
	while (InfFile.peek() != EOF)
	{
		InfFile >> Abo.fio; InfFile.get();
		InfFile >> Abo.phone; InfFile.get();
		InfFile >> Abo.tarif; InfFile.get();
		InfFile >> Abo.year; InfFile.get();
		Array.push_back(Abo);
	}
	InfFile.close();
	Abonent temp;
	int size = Array.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++) {
			if (Array[i].fio > Array[j].fio) {
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (Array[i].year == YEAR)
			arr.push_back(Array[i]);
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << "Subscriber's name: " << Abo.fio << "\n";
		cout << "Subscriber's number: " << Abo.phone << "\n";
		cout << "Tariff name: " << Abo.tarif << "\n";
		cout << "Year of connection: " << Abo.year << "\n";
		cout << "-----------------------------------" << endl;
	}
}
