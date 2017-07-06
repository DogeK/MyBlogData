#include <iostream>
#include <vector>

using namespace std;
int IsBit(int num,int index)
{
	cout << num << endl;
	num=num>>index;
	return (num&1);
}

void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
{
	if(data.size()<2)
		return ;
	int size=data.size();
	int temp=data[0];
	for(int i=1;i<size;i++)
		temp=temp^data[i];
	if(temp==0)
		return ;
	int index=0;
	while((temp&1)==0)
	{
		temp=temp>>1;
		++index;
	}
	cout << "index:" << index << endl;
	*num1 = 0;
	*num2 = 0;
	cout << num1 << num2 << endl;
	for(int i=0;i<size;i++)
	{
		cout << "adf" << endl;
		if(IsBit(data[i],index))
			*num1^=data[i];
		else
			*num2^=data[i];
		cout << "data[i]:" << data[i] << " num1:" << *num1 << " num2:" << *num2 << endl;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(4);
	v.push_back(2);
	int *num1, *num2;
	FindNumsAppearOnce(v, num1, num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}