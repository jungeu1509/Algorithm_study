#include <iostream>
using namespace std;

#define MOD 10007
int data[1001];

int func(int n) {
    if((data[n] > 0)|| n < 3) return data[n];
    data[n] = (func(n-1) + (func(n-2) * 2)) % MOD;
    return data[n];
}

int main() {
    int n;
    cin >> n;
    
    data[1] = 1; // 1
    data[2] = 3; // 11 = ㅁ
    //data[3] // 111 1= 1ㅁ(data[2]) / =1 ㅁ1 (data[1] * 2)
    
    cout << func(n);
    return 0;
}
