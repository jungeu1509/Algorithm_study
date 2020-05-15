#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define d_pow(x) pow(x,2)

double two_dot(int x1, int y1, int x2, int y2)
{
	return sqrt(d_pow((double)(x1-x2)) + d_pow((double)(y1 - y2)));
}

int main()
{
	int i, T;
	int x1, y1, r1;
	int x2, y2, r2;
	double len, r_sum;

	cin >> T;

	for(i=0;i<T;i++)
	{
		cin>>x1>>y1>>r1>>x2>>y2>>r2;

		len = two_dot(x1, y1, x2, y2);
		r_sum = r1 + r2;

		if(x1==x2 && y1==y2)
		{
			if(r1 == r2)
				cout << -1<<"\n";
			else
				cout << 0<<"\n";
		}
		else if(len > r_sum)
			cout << 0 <<"\n";
		else if(len == r_sum)
			cout << 1 <<"\n";
		else
		{
			if((r2 > len + r1)||(r1 > len + r2))
				cout <<0 <<"\n";
			else if((r2 == len + r1)||(r1 == len + r2))
				cout << 1 << "\n";
			else
				cout << 2 << "\n";
		}
	}
	return 0;
}
