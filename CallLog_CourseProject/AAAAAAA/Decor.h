#pragma once
#include <string>

using namespace std;

void Separator();
void LittleSeparator();
void PrintHeader(string str, int color);
void DeleteSymbol();
void SwitchWrongInput();
void ChangeColor(int color);
int SymbolCheck(char c);
bool IsDigit(char c);
bool IsEngLetter(char c);
int EnterNumber();
string EnterNumberInString();
double EnterDouble();
int NumberInputCheck(int index, int size);
void DeleteAllFromFile();
