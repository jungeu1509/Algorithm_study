#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    int count=1; //몇번째 악마의 수인지 세는 변수
    int number=666; //하나씩 올라가면서 찾을 수
    cin >> N;

    while(count != N)
    {
        number++;
        int temp = number; //3자리 수 씩 끊어 비교하기 위한 변수
        while(temp >= 666) //비교하는 수가 666보다 크거나 같은 수 여야 함
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
