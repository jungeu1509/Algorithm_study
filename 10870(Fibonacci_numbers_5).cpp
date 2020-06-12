#include <iostream>
using namespace std;

int fib(int input)
{
  if(input == 0)
    return 0;
  else if(input == 1)
    return 1;
  else
    return fib(input - 1) + fib(input -2);
}

int main()
{
	int N;
	cin >> N;
  cout << fib(N) << '\n';
	return 0;
}
