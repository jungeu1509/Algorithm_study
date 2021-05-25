#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int A, B, C;
	int i=0;
	cin >> A >> B >> C;

	if(B>=C)
	{
		cout << -1;
		return 0;
	}
	i = A / (C - B);
	while(1)
	{
		if( (A+(B*i)) < (C*i) )
		{
			break;
		}
		i++;
	}

	cout << i;
	return 0;
}
