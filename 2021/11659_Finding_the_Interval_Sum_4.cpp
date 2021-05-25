#include <iostream>
using namespace std;

#define MAX_NUM 100001

int numbers[MAX_NUM];
int sum[MAX_NUM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        cin >> numbers[i];
        sum[i] = sum[i-1] + numbers[i];
    }
    
    for(int k = 0; k < M; k++) {
        int i, j, answer;
        cin >> i >> j;
        cout << sum[j] - sum[i-1] << '\n';
    }
    
    return 0;
}
