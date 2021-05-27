#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int check_the_number(int i);

int main()
{
	int N;
	int ret = 0;
	
	cin >> N;
		
	for(int i = 1; i <= N ; i++)
		ret += check_the_number(i);
	cout << ret;
	return 0;
}

int check_the_number(int i)
{
	int a, b, c;
	a = i / 100;
	b = (i - (a * 100)) / 10;
	c = i % 10;
	
	if(a!=0)
	{
		if((a - b) == (b - c))
			return 1;
		else
			return 0;
	}
	return 1;
}
