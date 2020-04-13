#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A, B;
	int Change_A=0, Change_B=0;

	cin >> A >> B;

	Change_A = A/100 + (((A/10)%10)*10) + ((A%10)*100);
	Change_B = B/100 + (((B/10)%10)*10) + ((B%10)*100);
	

	if(Change_B>Change_A)
		cout<<Change_B;
	else
		cout<<Change_A;

	return 0;
}
