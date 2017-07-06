#include <iostream>

using namespace std;

int Sum_Solution(int n)
{
	int ans = n;
	ans && (ans += Sum_Solution(n-1));
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << Sum_Solution(3) << endl;
	return 0;
}