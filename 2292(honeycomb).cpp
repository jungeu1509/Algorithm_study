#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int input, number;
	int ret;

	cin >> input;

	number = input - 1;
	ret = 1;
	
	if(number <= 0)
	{
		cout << ret;
		return 0;
	}

	while(1)
	{
		number = number - (ret * 6);
		ret++;
		if(number<=0)
			break;
	}

	cout << ret;
	return 0;
}
