#include "Constants.h"
#include "Decor.h"
#include "Talk.h"
#include <conio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void WriteTalkToFile(TalkStruct talk) {
	ofstream File;
	File.open(DATABASE_FILE, ofstream::app);
	File << talk.number << endl;
	File << talk.fio << endl;
	File << talk.belonging << endl;
	File << talk.otherNumber << endl;
	File << talk.date << endl;
	File << talk.time << endl;
	File << talk.duration << endl;
	File << talk.tarif << endl;
	File.close();
}

void WriteInfoAboutTalk(TalkStruct talk, int index) {
	std::cout << index << ". Phone number: " << talk.number << "\n Owner's name: " << talk.fio;
	if (talk.belonging == 1)
		std::cout << "\n Incoming call\n Called by: ";
	else
		if (talk.belonging == 0)
			std::cout << "\n Outgoing call\n Called: " << talk.otherNumber;
		else
			std::cout << "\n Incoming/outcoming: NULL, number: NULL";
	std::cout << "\n Date: " << talk.date << "\n Time: " << talk.time << "\n Length in seconds: ";
	if (talk.duration >= 0)
		cout << talk.duration;
	else
		cout << "NULL";
	std::cout << "\n Tariff for a minute: ";
	if (talk.tarif >= 0)
		std::cout << talk.tarif;
	else
		std::cout << "NULL";
}

vector<TalkStruct> ReadTalksFromFile() {
	vector <TalkStruct> arr;
	TalkStruct talk;
	ifstream readFile;
	readFile.open(DATABASE_FILE);
	for (int i = 0; readFile.peek() != EOF; i++) {
		readFile >> talk.number; readFile.get();
		readFile >> talk.fio; readFile.get();
		readFile >> talk.belonging; readFile.get();
		readFile >> talk.otherNumber; readFile.get();
		readFile >> talk.date; readFile.get();
		readFile >> talk.time; readFile.get();
		readFile >> talk.duration; readFile.get();
		readFile >> talk.tarif; readFile.get();
		arr.push_back(talk);
	}
	readFile.close();
	return arr;
}

string SetNumber() {
	string str;
	cout << "Enter the subscriber's number: ";
	str = EnterNumberInString();
	return str;
}

string SetFio() {
	string str;
	cout << "Enter the abonent's name: ";
	cin >> str;
	return str;
}

int SetBelonging() {
	cout << "The call was incoming (1) or outgoing (0): ";
	char belonging = '2';
	while (1) {
		belonging = _getch();
		if (belonging == '1')
			return 1;
		if (belonging == '0')
			return 0;
	}
}

string SetOtherNumber(int belonging) {
	string str;
	if (belonging == '1')
		cout << "Enter the number that called: ";
	else {
		if (belonging == '0')
			cout << "Enter the number that is called: ";
		else
			cout << "Enter the other number: ";
	}
	cin >> str;
	return str;
}

string SetDate() {
	string str;
	cout << "Enter date of the call (yyyy.mm.dd): ";
	cin >> str;
	return str;
}

string SetTime() {
	string str;
	cout << "Enter time of call (ex. 23.16): ";
	cin >> str;
	return str;
}

int SetDuration() {
	int duration;
	cout << "Enter length of the call in seconds: ";
	duration = EnterNumber();
	return duration;
}

double SetTarif() {
	double tarif;
	cout << "Set tariff for one minute of calling: ";
	//tarif = enterDouble();
	cin >> tarif;
	return tarif;
}

void AddTalk() {
	string buf;
	system("cls");
	TalkStruct talk;
	talk.number = SetNumber();
	cout << endl;
	talk.fio = SetFio();
	talk.belonging = SetBelonging();
	cout << endl;
	talk.otherNumber = SetOtherNumber(talk.belonging);
	talk.date = SetDate();
	talk.time = SetTime();
	talk.duration = SetDuration();
	cout << endl;
	talk.tarif = SetTarif();
	WriteTalkToFile(talk);
	std::system("pause");
	std::system("cls");
}

void DeleteTalk() {
	vector<TalkStruct> arr = ReadTalksFromFile();
	int s = arr.size();
	int index = 0;
	char check;
	cout << "Enter the number of a log that you would like to delete: ";
	index = EnterNumber();
	if (NumberInputCheck(index, s) == 0)
		return;
	ChangeColor(12);
	cout << "\nConfirm deletion: press 1 to continue, or any other key to cancel. ";
	ChangeColor(15);
	check = _getch();
	if (check != '1') {
		cout << ENTER_ANY_CHARACTER << endl;
		std::system("pause");
		return;
	}
	arr.erase(arr.begin() + (index - 1));
	DeleteAllFromFile();
	for (int j = 0; j < arr.size(); j++)
		WriteTalkToFile(arr[j]);
	cout << "Deleted successfully.\n";
	std::system("pause");
	system("cls");
}

void EditTalk() {
	vector<TalkStruct> arr = ReadTalksFromFile();
	int s = arr.size();
	TalkStruct talk;
	string tmp;
	int index;
	cout << "Enter the number of a log that you would like to edit: ";
	index = EnterNumber();
	if (NumberInputCheck(index, s) == 0)
		return;
	char choice;
	index--;
	cout << "\nWhat do you want to edit? ";
	cout << "\n 1 - Subscriber's name\n 2 - Phone number\n 3 - Is it an incoming/outgoing call\n 4 - Another number\n 5 - Date\n 6 - Time\n 7 - Call duration\n 8 - Tariff\n ";
	choice = _getch();
	switch (choice) {
	case '1':
		arr[index].fio = SetFio(); break;
	case '2':
		arr[index].number = SetNumber(); break;
	case '3':
		arr[index].belonging = SetBelonging(); break;
	case '4':
		arr[index].otherNumber = SetOtherNumber(arr[index].belonging); break;
	case '5':
		arr[index].date = SetDate(); break;
	case '6':
		arr[index].time = SetTime(); break;
	case '7':
		arr[index].duration = SetDuration(); break;
	case '8':
		arr[index].tarif = SetTarif(); break;
	default:
		SwitchWrongInput(); return;
	}
	DeleteAllFromFile();
	for (int j = 0; j < arr.size(); j++)
		WriteTalkToFile(arr[j]);
	cout << "\nEdited successfully!\n" << endl;
	system("pause");
	system("cls");
}

void ViewTalkVector(vector<TalkStruct> arr, int s) {
	TalkStruct talk;
	for (int i = 0; i < s; i++) {
		WriteInfoAboutTalk(arr[i], i + 1);
		LittleSeparator();
	}
}

void ViewTalk() {
	system("cls");
	vector<TalkStruct> arr = ReadTalksFromFile();
	int s = arr.size();
	ViewTalkVector(arr, s);
	system("pause");
	system("cls");
}

int RecordFits(TalkStruct talk, int index) {
	WriteInfoAboutTalk(talk, index + 1);
	LittleSeparator();
	index++;
	return index;
}

TalkStruct ClearTalk() { 
	TalkStruct talk;
	talk.number = "NULL";
	talk.fio = "NULL";
	talk.belonging = -1;
	talk.otherNumber = "NULL";
	talk.date = "NULL";
	talk.time = "NULL";
	talk.duration = -1;
	talk.tarif = -1;
	return talk;
}

void SearchTalk() {
	int found = 0;
	double tarif = 0;
	char choice;
	int cycle = 1;
	string str;
	TalkStruct talk;
	talk = ClearTalk();
	vector<TalkStruct> arr = ReadTalksFromFile();
	while (cycle) {
		system("cls");
		cout << "What fields to fill for search?\n Field values right now (NULL - empty field. It can be left if it does not matter in search): \n";
		WriteInfoAboutTalk(talk, 1);
		LittleSeparator();
		cout << "\n 1 - Subscriber's name\n 2 - Phone number\n 3 - Is it an incoming/outgoing call\n 4 - Another number\n 5 - Date\n 6 - Time\n 7 - Call duration\n 8 - Tariff\n 9 - Clear all fields\n 0 - Next\n";
		choice = _getch();
		switch (choice) {
		case '0':
			cycle = 0; break;
		case '1':
			talk.fio = SetFio(); break;
		case '2':
			talk.number = SetNumber(); break;
		case '3':
			talk.belonging = SetBelonging(); break;
		case '4':
			talk.otherNumber = SetOtherNumber(-1); break;
		case '5':
			talk.date = SetDate(); break;
		case '6':
			talk.time = SetTime(); break;
		case '7':
			talk.duration = SetDuration(); break;
		case '8':
			talk.tarif = SetTarif(); break;
		case '9':
			talk = ClearTalk(); break;
		default:
			cout << WRONG_INPUT << endl;
			std::system("pause");
			break;
		}
	}
	LittleSeparator();
	for (int i = 0; i < arr.size(); i++) {
		if (talk.number == "NULL" || talk.number == arr[i].number)
			if (talk.fio == "NULL" || talk.fio == arr[i].fio)
				if (talk.belonging == -1 || talk.belonging == arr[i].belonging)
					if (talk.otherNumber == "NULL" || talk.otherNumber == arr[i].otherNumber)
						if (talk.date == "NULL" || talk.date == arr[i].date)
							if (talk.time == "NULL" || talk.time == arr[i].time)
								if (talk.duration == -1 || talk.duration == arr[i].duration)
									if (talk.tarif == -1 || talk.tarif == arr[i].tarif)
									{
										found = 1;
										WriteInfoAboutTalk(arr[i], i + 1);
										LittleSeparator();
									}

	}
	if (found == 0)
		cout << "\n No logs meet entered parameters!\n";
	system("pause");
	system("cls");
}

void FilterTalk() {
	system("cls");
	int found = 0;
	char choice;
	double tarif = 0;
	string str;
	vector<TalkStruct> arr = ReadTalksFromFile();
	cout << "Filter by which feature?";
	cout << "\n 1 - Subscriber's name\n 2 - Phone number\n 3 - Is it an incoming/outgoing call\n 4 - Another number\n 5 - Date\n 6 - Time\n 7 - Call duration\n 8 - Tariff\n 0 - Next\n";
	choice = _getch();
	Separator();
	switch (choice) {
	case '0':
		system("pause"); return;
	case '1':
		str = SetFio();
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].fio == str) {
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	case '2':
		str = SetNumber();
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].number == str) {
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	case '3':
		choice = SetBelonging();
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].belonging == choice) {
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	case '4':
		str = SetOtherNumber(2);
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].otherNumber == str)
			{
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	case '5':
		str = SetDate();
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].date == str) {
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	case '7':
		str = SetTime();
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].time == str) {
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	case '8':
		choice = SetDuration();
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].duration == choice)
			{
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	case '9':
		tarif = SetTarif();
		for (int i = 0, index = 0; i < arr.size(); i++) {
			if (arr[i].tarif == tarif) {
				index = RecordFits(arr[i], index);
				found = 1;
			}
		}
		break;
	default:
		cout << WRONG_INPUT << endl;
		std::system("pause");
		return;
	}
	if (found == 0)
		cout << "\n No logs meet entered parameters!\n";
	system("pause");
	system("cls");
}

void SortTalk() {
	char choice;
	vector<TalkStruct> arr = ReadTalksFromFile();
	cout << "Sort by which feature?";
	cout << "\n 1 - Subscriber's name\n 2 - Phone number\n 3 - Another number\n 4 - Date\n 5 - Call duration\n 0 - Next\n";
	choice = _getch();
	Separator();
	system("cls");
	TalkStruct temp;
	int s = arr.size();
	int min = 0;
	switch (choice) {
	case '0':
		system("pause"); return;
	case '1':
		for (int i = 0; i < s; i++) {
			min = i;
			for (int j = i + 1; j < s; j++) {
				if (arr[i].fio > arr[j].fio)
					min = j;
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		ViewTalkVector(arr, s);
		break;
	case '2':
		for (int i = 0; i < s; i++) {
			min = i;
			for (int j = i + 1; j < s; j++) {
				if (arr[i].number > arr[j].number)
					min = j;
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		ViewTalkVector(arr, s);
		break;
	case '3':
		for (int i = 0; i < s; i++) {
			min = i;
			for (int j = i + 1; j < s; j++) {
				if (arr[i].otherNumber > arr[j].otherNumber)
					min = j;
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		ViewTalkVector(arr, s);
		break;
	case '4':
		for (int i = 0; i < s; i++) {
			min = i;
			for (int j = i + 1; j < s; j++) {
				if (arr[i].date > arr[j].date)
					min = j;
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		ViewTalkVector(arr, s);
		break;
	case '5':
		for (int i = 0; i < s; i++) {
			min = i;
			for (int j = i + 1; j < s; j++) {
				if (arr[i].duration > arr[j].duration)
					min = j;
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		ViewTalkVector(arr, s);
		break;
	default:
		cout << WRONG_INPUT << endl;
		std::system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
	return;
}

void Task() {
	vector<TalkStruct> arr;
	int foundDate = 0;
	string FIO;
	cout << "Enter the name of an abonent for which you need to see a list of calls and sum for outgoing calls for some period: ";
	cin >> FIO;
	string date1, date2;
	cout << "Enter lower range of search (yyyy.mm.dd): ";
	cin >> date1;
	cout << "Enter higher range of search (yyyy.mm.dd): ";
	cin >> date2;
	if (date1 > date2) {
		cout << "Wrong input!\n";
		system("pause");
		return;
	}
	TalkStruct talk;
	ifstream readFile;
	readFile.open(DATABASE_FILE);
	for (int i = 0; readFile.peek() != EOF; i++) {
		readFile >> talk.number; readFile.get();
		readFile >> talk.fio; readFile.get();
		readFile >> talk.belonging; readFile.get();
		readFile >> talk.otherNumber; readFile.get();
		readFile >> talk.date; readFile.get();
		readFile >> talk.time; readFile.get();
		readFile >> talk.duration; readFile.get();
		readFile >> talk.tarif; readFile.get();
		if (talk.fio == FIO)
			arr.push_back(talk);
	}
	readFile.close();
	if (arr.size() == 0) {
		cout << "No information for such subscriber!\n";
		system("pause");
		return;
	}
	double sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].date > date1 && arr[i].date < date2) {
			WriteInfoAboutTalk(arr[i], i + 1);
			if (arr[i].belonging == 0)
				sum += arr[i].tarif * (round(arr[i].duration / 60));
			LittleSeparator();
		}
	}
	cout << "Sum in total: " << sum << endl;
	system("pause");
	system("cls");
	return;
}
