#include <iostream>
using namespace std;

int data[1001];

int func(int N) {
    if(data[N] > 0) return data[N];
    data[N] = (func(N-1) + func(N-2)) % 10007;
    return data[N];
}

int main() {
    int N;
    data[1] = 1;
    data[2] = 2;
    cin >> N;
    cout << func(N) << '\n';
    return 0;
}
