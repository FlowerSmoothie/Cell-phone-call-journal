#pragma once
#include <string>

using namespace std;

struct TalkStruct
{
	string fio;
	string number;
	int belonging;
	string otherNumber;
	string date;
	string time;
	int duration;
	double tarif;
};

void AddTalk();
void DeleteTalk();
void EditTalk();
void ViewTalk();
void FilterTalk();
void SearchTalk();
void SortTalk();
void Task();
int NumberInputCheck(int index, int choice);
void WriteInfoAboutTalk(TalkStruct talk, int index);
string SetNumber();
string SetFio();
int SetBelonging();
string SetOtherNumber(int belonging);
string SetDate();
string SetTime();
int SetDuration();
double SetTarif();
