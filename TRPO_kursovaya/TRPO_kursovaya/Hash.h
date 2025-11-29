#pragma once
#include <iostream>
#include <string>
using namespace std;
class Hash
{
    string hash;
    int recieveCod(int el);
    int getSum(string str);
public:
    string getHash(string userString);
};
