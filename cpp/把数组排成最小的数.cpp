#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
// 1 represent s1 < s2, otherwise s1 > s2
int cmpMinChar(string s1, string s2) {
	int flag = s1.length() < s2.length() ? 1 : 0;
	int length = s1.length() < s2.length() ? s1.length() : s2.length();
	int i = 0;
	for (i = 0; i < length; i++) {
		if (s1[i] < s2[i])
			return 1;
		else if (s1[i] > s2[i])
			return 0;
	}
	if (flag)
		for (; i < s2.length(); i++)
			if (s2[i] > s2[0])
				return 1;
			else if (s2[i] < s2[0])
				return 0;
	else
		for (; i < s1.length(); i++)
			if (s1[i] > s1[0])
				return 0;
			else if (s1[i] < s1[0])
				return 1;
	return 1;
}

int cmpMinChar1(string s1, string s2) {
	string ts1 = s1+s2;
	string ts2 = s2+s1;
	return ts1 < ts2;
}

void quick_sort(vector<string> &input, int first, int last) {
	if (first > last) return;
	int left = first, right = last;
	string temp = input[first];
	while (left < right) {
		while (left<right && cmpMinChar1(temp, input[right])) right--;
		input[left] = input[right];
		while(left<right && cmpMinChar1(input[left], temp)) left++;
		input[right] = input[left];
	}
	input[left] = temp;
	quick_sort(input, first, left-1);
	quick_sort(input, left+1, last);
}

string PrintMinNumber(vector<int> numbers) {
	vector<string> stirngOfNumbers;
	stringstream ss;
	for (int i = 0; i < numbers.size(); i++) {
		ss << numbers[i];
		stirngOfNumbers.push_back(ss.str());
		ss.str("");
	}
	quick_sort(stirngOfNumbers, 0, stirngOfNumbers.size()-1);

	string ans = "";
	for (int i = 0; i < stirngOfNumbers.size(); i++)
		ans += stirngOfNumbers[i];
	return ans;	
}



int main(int argc, char const *argv[])
{
	vector<int> input;
	input.push_back(3);
	input.push_back(33321);
	input.push_back(34);
	input.push_back(331);
	input.push_back(38);
	cout << PrintMinNumber(input) << endl;



	return 0;
}