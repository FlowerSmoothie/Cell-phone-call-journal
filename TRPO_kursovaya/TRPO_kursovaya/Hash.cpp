#include <string>
#include <iostream>
#include "Hash.h"
using namespace std;

int Hash::recieveCod(int el)
{
    el += 256;
    while (!((el <= 57 && el >= 48) || (el <= 90 && el >= 65) || (el <= 122 && el >= 97)))
    {
        if (el < 48) el += 24;
        else el -= 47;
    }
    return el;
}

int Hash::getSum(string str) {
    int sault = 0, len = 0;
    for (; len < str.size(); len++)
        sault += int(str[len]);
    return sault;
}

string Hash::getHash(string userString)
{
    int length = 16;
    int minlen = 2, realMinlen = 0;
    int sault_orig = this->getSum(userString), length_orig = (userString.size());
    while (minlen <= length) realMinlen = (minlen *= 2);
    while (minlen < length_orig) minlen *= 2; minlen *= 2;
    int add_count = minlen - length_orig;
    for (int i = 0; i < add_count; i++)
        userString += this->recieveCod(userString[i] + userString[i + 1]);
    int maxSault = this->getSum(userString);
    int maxlen = userString.size();
    while (userString.size() != realMinlen)
        for (int i = 0, center = userString.size() / 2; i < center; i++) {
            this->hash += this->recieveCod(userString[center + i] + userString[center - i]);
            userString = this->hash;
            this->hash.clear();
        }
    int res = realMinlen - length;
    for (int i = 0, count = realMinlen / res; this->hash.size() < (length - 4); i++)
    {
        if (i % count == 0)
            this->hash += this->recieveCod(userString[i] + userString[++i]);
        else
            this->hash += userString[i];
    }
    this->hash += this->recieveCod(sault_orig);
    this->hash += this->recieveCod(length_orig);
    this->hash += this->recieveCod(maxSault);
    this->hash += this->recieveCod(maxlen);
    return this->hash;
    return "";
}
