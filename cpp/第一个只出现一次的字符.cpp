#include <iostream>


using namespace std;

int FirstNotRepeatingChar(string str)
{
	int num['z'+10];
	memset(num, 0, sizeof(int)*('z'+10));
	for (int i = 0; i < str.length(); i++)
		num[str[i]]++;

	for (int i = 0; i < str.length(); i++)
		if (num[str[i]] == 1)
			return i;
	return -1;
}

int main(int argc, char const *argv[])
{
	string input = "kYVmIJVzYWPQLtIdKMmvkVSoKtqJANOfCCOfLVJEjjhbnPrDOwKCDeqhts";
	cout << FirstNotRepeatingChar(input) << endl;
	return 0;
}