#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int input, i;
	int num = 0;
	cin >> input;
	for(i = 0;i< ((input*2)-1);i++)
	{
		for(int j=0;j<num;j++)
			cout << " ";
		for(int j=0;j<((input*2-1)-(num*2));j++)
			cout << "*";
		(i<(input-1))?num++:num--;
		cout << "\n";
	}
	return 0;
}
