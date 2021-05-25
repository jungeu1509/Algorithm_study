#include <iostream>
using namespace std;

long long int fec(int input)
{
  if(input <= 1) // 0! = 1
    return 1;
  else
    return input * fec(input-1);
}

int main()
{
	int N;
	cin >> N;
  cout << fec(N) << '\n';
	return 0;
}
