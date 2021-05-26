#include <iostream>
using namespace std;

int coin[10];

int main() {
    int N, K, left, answer=0;
    cin >> N >> K;
    left = K;
    for(int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    
    for(int i = N-1; i >= 0; i--) {
        int temp = left / coin[i];
        if(temp > 0) {
            left -= temp * coin[i];
            answer += temp;
        }
    }
    cout << answer << '\n';
    return 0;
}
