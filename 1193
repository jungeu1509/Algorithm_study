#include <iostream>
using namespace std;

int main()
{
	int input;
	int ret=0, i=0;

	cin >> input;
	ret = input;

	while(1)
	{
		ret -= i;
		if(ret<=0)
		{break;}
		i++;
	}

	if(i%2 == 1)
		cout << i-(i+ret-1) <<"/"<<(i+ret);
	else
		cout << (i+ret) <<"/"<< i - (i+ret-1);

	return 0;
}
