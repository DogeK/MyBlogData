#include <iostream>
#include <vector>
#include <map>
#define maxn 10000

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	std::map<int, int> intMap;
	map<int, int>::iterator it;
	for (int i = 0; i < numbers.size(); i++)
	{
		
		it = intMap.find(numbers[i]);
		if (it == intMap.end())
			intMap.insert(pair<int, int>(numbers[i], 1));
		else
			intMap[numbers[i]]++;
	}
	int max = 0, index;
	for (it = intMap.begin(); it != intMap.end(); it++)
		if (it->second > max)
		{
			max = it->second;
			index = it->first;
		}
	if (max > numbers.size()/2)
		return index;
	return 0;
}

void mapTest()
{
	std::map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(4, 50));
	map<int, int>::iterator it;
	it = m.find(3);
	if (it == m.end())
	{
		cout << "Not find" << endl;
		m.insert(pair<int, int>(3, 20));
	}	
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	// MoreThanHalfNum_Solution(v);
	mapTest();
	return 0;
}