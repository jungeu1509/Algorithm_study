#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100

bool prime(int Number)
{
    if(Number == 1)
        return 0;
    for(int i = 2; i <= (Number/2); i++)
        if(Number % i == 0)
            return 0;
    return 1;
}

int main()
{
    int N, count = 0;
    int arr[MAX_SIZE] = {0, };
    
    cin >> N;
    for(int i=0; i< N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++)
        count += prime(arr[i]);
    
    cout << count << '\n';
    return 0;
}
