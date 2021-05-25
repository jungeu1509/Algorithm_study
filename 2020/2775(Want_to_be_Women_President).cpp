#include <iostream>
using namespace std;

#define MAXVAL 15
int apt[MAXVAL][MAXVAL] = {0, };

int count_people(int k, int n);

int main()
{
	int T, k, n;
	for(int i = 1; i< MAXVAL; i++)
		apt[0][i] = i;

	cin >> T;
	
	for(int j=0; j<T; j++)
	{
		cin >> k >> n;
		cout << count_people(k, n) << "\n";
	}
	return 0;
}

int count_people(int k, int n)
{
	if(apt[k][n]!=0)
		return apt[k][n];
		
	for(int i = 1; i<=n; i++)
	{
		apt[k][n] += count_people(k-1, i);
	}
	
	return apt[k][n];
}
