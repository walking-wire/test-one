#include<iostream>
//cin 键入， 输入 类比 scanf cin输入流，从输入流中抽取字符 无需%s,%d 智能对象 
int main()
{
	using namespace std;
	int x = 0;
	cin >> x;
	cout << x << endl;
	cout << "try a test about number: " << x << " work right" << endl; 
	cout << "try a test about number: "
		 << x 
		 << " work right" 
		 << endl; 
	return 0;
}
