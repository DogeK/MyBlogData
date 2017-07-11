#include <iostream>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n <= 0 || m <= 0) return -1;
	int ans = 0;
	for (int i = 2; i <= n; i++)
		ans = (ans + m)%i;
	return ans;
}


int main(int argc, char const *argv[])
{
	cout << LastRemaining_Solution(5,2) << endl;
	return 0;
}