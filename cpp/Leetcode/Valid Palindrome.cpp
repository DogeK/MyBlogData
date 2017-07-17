#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	if (s.empty()) return true;
	int first = 0, last = s.length()-1;
	while (first < last) {
		while(s[first]<'0' || (s[first]>'9' && s[first]<'A') || s[first]>'z' || (s[first]>'Z'&&s[first]<'a')) first++;
		while(s[last]<'0' || (s[last]>'9' && s[last]<'A') || s[last]>'z' || (s[last]>'Z'&&s[last]<'a')) last--;
		char c1 = s[first]>'Z'?s[first]-32:s[first];
		char c2 = s[last]>'Z'?s[last]-32:s[last];

		if (c1 == c2 && first < last) {

			first++;
			last--;
		} else if (first < last) {
			return false;
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	string s = "a.";
	cout << isPalindrome(s) << endl;
	return 0;
}