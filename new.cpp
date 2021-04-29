#include<iostream>

int main()
{
	using namespace std;
	int *p = new int;
	*p = 9;
	int *q = new int [6];
	q[0] = 1;
	q[1] = 2;
	cout << *p << endl;
	for(int i = 0; i< 6; i++)
	{
		cout << q[i] << endl;
	}
	delete p;
	delete [] q;
	return 0;
}
