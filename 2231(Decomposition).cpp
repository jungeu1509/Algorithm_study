#include <iostream>
using namespace std;

int main()
{
  long N, temp, sum = 0, i;
  int digit = 0;
  bool find = 0;

  cin >> N;
    
  temp = N;
  while(temp)
  {
    temp /= 10;
    digit++;
  }

  for(i = (N - digit * 9); i <= N; ++i)
  {
    sum = i;
    temp = i;

    while(temp)
    {
      sum += (temp % 10);
      temp /= 10;
    }
    if(sum == N)
    {
        find = 1;
        cout << i << '\n';
        return 0;
    }
  }

  if(find == 0)
    cout << '0' << '\n';
  return 0;
}
