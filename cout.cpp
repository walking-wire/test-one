#include<iostream>
//测试C++中的输入输出，cout:输出流，endl:光标换行，<< 将字符串置入输出流中，为重载运算符 
// cout 类比printf cout 能够自动识别变量类型，而printf不能，只能用 %s, %d 
int main()
{
	using namespace std;
	cout << " just a test for C++";
	cout << endl;
	cout << " just a test for C++";
	cout << endl;
	cout << " just another tset for C++\n";
	cout << "yes" << endl;
	cout << "wrong";
	cout << endl;
	int testnumber = 250;
	cout << testnumber; 
	return 0;
 } 
