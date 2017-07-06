#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int> &input, int begin, int end)
{
	int first = begin;
	int last = end;
	int pivot = input[first];
	while (first < last)
	{
		while (first < last && input[last] >= pivot) last--;
		input[first] = input[last];
		while (first < last && input[first] <= pivot) first++;
		input[last] = input[first];
	}
	input[first] = pivot;
	return first;
}
vector<int> GetLeastNumbers_Solution(vector<int> &input, int k)
{
	int len=input.size();
	vector<int> res;
	if(len==0||k>len||k<=0) return res;
	if(len==k) return input;
	int start=0;
	int end=len-1;
	int index=Partition(input,start,end);
	while(index!=(k-1))
	{
		if(index>k-1)
		{
			end=index-1;
			index=Partition(input,start,end);
		}
		else
		{
			start=index+1;
			index=Partition(input,start,end);
		}
	}
	for (int i = 0; i < k; i++)
		res.push_back(input[i]);
	return res;
}


void heapAdjust(vector<int> &arr, int currentIndex, int length)
{
	int temp = arr[currentIndex];
	int child = 2*currentIndex+1;
	while(child < length)
	{
		if (child+1 < length && arr[child] > arr[child+1] )
			child++;
		if (arr[currentIndex] > arr[child])
		{
			arr[currentIndex] = arr[child];
			currentIndex = child;
			child = 2*currentIndex+1;
		}
		else
			break;
		arr[currentIndex] = temp;
	}
	
}

void buildingHeap(vector<int> &arr)
{
	for (int i = (arr.size()-1)/2; i >= 0; i--)
		heapAdjust(arr, i, arr.size());	
}

// vector<int> GetLeastNumbers_Solution(vector<int> &input, int k)
// {
// 	buildingHeap(input);

// 	vector<int> ans;
// 	int n = input.size()-k-1;
// 	for (int i = input.size()-1; i > n; i--)
// 	{
// 		ans.push_back(input[0]);
// 		int temp = input[i]; input[i] = input[0]; input[0] = temp;
// 		heapAdjust(input, 0, i);
// 	}
// 	return ans;
// }

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(6);
	v.push_back(2);
	v.push_back(7);
	v.push_back(3);
	v.push_back(8);

	std::vector<int> ans = GetLeastNumbers_Solution(v, 5);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}