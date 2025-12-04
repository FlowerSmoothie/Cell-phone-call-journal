#include <string>
#include "Constants.h"

using namespace std;

int GetSum(string str)
{
	int salt = 0, len = 0;
	while (len < str.size())
	{
		salt += int(str[len]);
		len++;
	}
	return salt;
}

int RecieveCode(int a)
{
	a += 256;
	while (!((a <= 57 && a >= 48) || (a <= 90 && a >= 65) || (a <= 122 && a >= 97)))
	{
		if (a < 48) a += 24;
		else a -= 47;
	}
	return a;
}

string GetHash(string str)
{
	string hash;
	int length = HASH_LENGTH;
	int minlength = 2, realminlength = 0;
	int origsalt = GetSum(str), origlen = str.size();
	while (minlength <= length)
		realminlength = (minlength *= 2);
	while (minlength < origlen)
		minlength *= 2;
	int add = minlength - origlen;
	for (int i = 0; i < add; i++)
		str += RecieveCode(str[i] + str[i + 1]);
	int maxSalt = GetSum(str);
	int maxLength = str.size();
	while (str.size() != realminlength)
		for (int i = 0, center = str.size() / 2; i < center; i++) {
			hash += RecieveCode(str[center + i] + str[center - i]);
			str = hash;
			hash.clear();
		}
	int res = realminlength - length;
	for (int i = 0, count = realminlength / res; hash.size() < (length - 4); i++)
	{
		if (i % count == 0)
			hash += RecieveCode(str[i] + str[++i]);
		else
			hash += str[i];
	}
	hash += RecieveCode(origsalt);
	hash += RecieveCode(origlen);
	hash += RecieveCode(maxSalt);
	hash += RecieveCode(maxLength);
	return hash;
}