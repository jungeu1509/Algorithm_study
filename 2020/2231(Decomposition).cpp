#include <iostream>
using namespace std;

int main()
{
    int N, temp, sum = 0, i, digit = 0;

    cin >> N;
    temp = N;

    while(temp)
    {
        temp /= 10;
        digit++;
    }

    for(i = (N - digit * 9); i <= N; ++i)
    {
        if(i < 1)
            continue;
        sum = temp = i;
        while(temp)
        {
            sum += (temp % 10);
            temp /= 10;
        }
        if(sum == N)
        {
            cout << i;
            return 0;
        }
    }

    cout << '0';
    return 0;
}
