#include <iostream>
using namespace std;

int main()
{
	int A, B, V, tmp;
	int height=0, cnt=1;

	cin >> A >> B >> V;	
	tmp = A-B;
	
	if((V-A)/tmp > 1)
	{
		cnt = (V-A)/tmp;
		V -= (cnt++)*(A-B);
	}
	
	while(1)
	{
		height += A;
		if(height >= V)
			break;
		
		height -= B;
		cnt++;
	}
	cout << cnt;
	return 0;
}
