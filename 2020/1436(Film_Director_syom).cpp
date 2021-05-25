#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, count=1, number=666;
    cin >> N;

    while(count != N)
    {
        number++;
        int temp = number;
        while(temp >= 666)
        {
            if(temp%1000 == 666)
            {
                count++;
                break;
            }
            temp /= 10;
        }
    }

    cout << number << "\n";
    return 0;
}
