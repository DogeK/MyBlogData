#include <iostream>

using namespace std;

bool IsBigEndian()
{
    int a =1 ; 
    if(((char*)&a)[3] ==1)
        return true ;
    else
        return false ;
}

bool test_and_set (bool *target) {  
	cout << "address:" << target << " value:" << *target << endl;
    bool rv = *target; 
    *target = true; 
    return rv;
}

int main(int argc, char const *argv[])
{
	bool fl = false;
	cout << test_and_set(&fl) << endl;
	cout << fl << endl;
	return 0;
}