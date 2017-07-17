#include <iostream>
#include <math.h>

using namespace std;

int Add(int num1, int num2)
{
	int carry = 0;
	int ans = 0;
	int length1 = 0, length2 = 0;
	int tn1 = num1, tn2 = num2;
	while(tn1)
	{
		length1++;
		tn1 = tn1>>1;
	}
	while(tn2)
	{
		length2++;
		tn2 = tn2>>1;
	}
	cout << length1 << " " << length2 << endl;
	int lengthLong = length1>length2?length1:length2;
	int lengthShort = length1>length2?length2:length1;
	int i = 0;
	for (; i < lengthLong; i++)
	{
		int t1 = num1&(1<<i);
		int t2 = num2&(1<<i);
		int temp = t1|t2;
		if (i < lengthShort)
		{	
			if ((t1&t2) == 1)
			{
				ans = ans&(1<<i)
				ans += carry*(int)pow(2, i);
				carry = 1;
			}
			else
			{
				ans += (temp?temp^carry:carry)*(int)pow(2, i);
				carry = temp&carry;
			} 
		}
		else
		{
			ans += (temp^carry)*(int)pow(2, i);
			carry = temp&carry;
		}
	}
	ans += carry*(int)pow(2, i);
	return ans;
}


int main(int argc, char const *argv[])
{
	cout << Add(5, 7) << endl;
	// cout << (7&2) << endl;
	return 0;
}