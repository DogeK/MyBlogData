#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		int t = i;
		while(t != 0)
		{
			if (t % 10 == 1)
				tmp++;
			t = t/10;
		}
		ans += tmp;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << NumberOf1Between1AndN_Solution(13) << endl;

	return 0;
}