#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
	int dp[array.size()];
	memset(dp, 0, sizeof(int)*array.size());
	dp[0] = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		if (dp[i-1]+array[i] > 0)	dp[i] = dp[i-1]+array[i];
		else dp[i] = 0;
	}
	int max = dp[0];
	for (int i = 1; i < array.size(); i++)
		if (dp[i] > max) max = dp[i];
	if (!max)
	{
		max = array[0];
		for (int i = 1; i < array.size(); i++)
			if (array[i] > max) max = array[i];
	}
	return max;
}

int main(int argc, char const *argv[])
{
	vector<int> input;
	input.push_back(1);
	input.push_back(-2);
	input.push_back(3);
	input.push_back(10);
	input.push_back(-4);
	input.push_back(7);
	input.push_back(2);
	input.push_back(-5);
	cout << FindGreatestSumOfSubArray(input) << endl;
	return 0;
}